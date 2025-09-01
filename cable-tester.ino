#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/power.h>

// --- Pin Tanımları ---
const int buttonPin = 2;              // Buton D2 → GND
const int modLed = 3;                 // 10. LED (mod LED)
const int ledPins[9] = {4,5,6,7,8,9,10,11,12}; // 1-9 LED pinleri

// --- Değişkenler ---
volatile bool isSleeping = false;     // Uyku durumu
int speedMode = 0;                    // 0 = 0.5s, 1 = 1s
unsigned long ledInterval[2] = {500, 1000}; // ms cinsinden mod süreleri
int currentLed = 0;                   // Şu an yanan LED (0-8)

// Buton zaman ölçümü
bool buttonPressed = false;
unsigned long pressStart = 0;

// --- Uyandırma ISR ---
void wakeUp() {
  // ISR içinde minimum iş
  // Boş bırakıyoruz, loop long press kontrolü yapacak
}

// --- Uykuya geçiş ---
void goToSleep() {
  // Tüm LED’leri kapat
  for(int i=0; i<9; i++) digitalWrite(ledPins[i], LOW);
  digitalWrite(modLed, LOW);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  // Uyandırma için butona attachInterrupt kullanıyoruz, ama sadece ISR tetikleyecek
  attachInterrupt(digitalPinToInterrupt(buttonPin), wakeUp, FALLING);

  isSleeping = true;
  sleep_cpu(); // uykuya gir

  // Uyandıktan sonra
  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(buttonPin));

  currentLed = 0; // uykudan çıkınca LED1’den başla
}

// --- Setup ---
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(modLed, OUTPUT);
  digitalWrite(modLed, LOW);

  for(int i=0; i<9; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // Açılışta direkt uykuya geç
  goToSleep();
}

// --- Loop ---
void loop() {

  // --- Buton okuma ---
  int buttonState = digitalRead(buttonPin);

  if(!isSleeping) {
    // --- Normal mod ---
    if(buttonState == LOW && !buttonPressed) {
      // Butona ilk basış
      buttonPressed = true;
      pressStart = millis();
    }

    if(buttonState == HIGH && buttonPressed) {
      // Buton bırakıldı
      unsigned long pressTime = millis() - pressStart;
      buttonPressed = false;

      if(pressTime < 1000) {
        // Kısa basma → hız modu değiştir
        speedMode = !speedMode;
      } else {
        // Uzun basma → uykuya geç
        goToSleep();
        return; // loop uyku sonrası tekrar başlar
      }
    }

    // --- LED kontrolü ---
    static unsigned long lastLedChange = 0;
    if(millis() - lastLedChange >= ledInterval[speedMode]) {
      lastLedChange = millis();

      // Önce tüm LED’leri kapat
      for(int i=0; i<9; i++){
        digitalWrite(ledPins[i], LOW);
      }

      // Şu anki LED’i yak
      digitalWrite(ledPins[currentLed], HIGH);

      // Mod LED kısa yanıp sönsün
      digitalWrite(modLed, HIGH);
      delay(50);
      digitalWrite(modLed, LOW);

      // Sonraki LED’e geç
      currentLed++;
      if(currentLed >= 9) currentLed = 0;
    }

  } else {
    // --- Uyku modu ---
    if(buttonState == LOW && !buttonPressed) {
      buttonPressed = true;
      pressStart = millis();
    }

    if(buttonState == HIGH && buttonPressed) {
      unsigned long pressTime = millis() - pressStart;
      buttonPressed = false;

      if(pressTime >= 1000) {
        // Uzun basma → uyan
        isSleeping = false;
        currentLed = 0; // uyanınca LED1’den başla
      }
      // Kısa basma ignore
    }
  }
}

# UNI-T UT681C Kablo Test Cihazı – Tamir ve Şarjlı Hale Getirme

## 📖 Proje Hakkında
Bu projede, arızalanan **UNI-T UT681C kablo test cihazını** yeniden hayata döndürdüm.  
Cihazın orijinal MCU'su **STC15W204S** kısa devre yapmıştı. Aynı MCU'yu bulup programlamak hem zor hem de uzun bir süreçti. Bu yüzden **Arduino Nano** kullanarak cihazı yeniden tasarladım.  

Ayrıca cihazı **şarj edilebilir** hale getirerek modernize ettim.

---

## 🔧 Yapılan İşlemler
1. Cihazın MCU’sunun (STC15W204S) kısa devre yaptığı belirlendi.
2. Orijinal MCU yerine **Arduino Nano** programlandı ve test edildi.
3. Nano üzerindeki gereksiz enerji tüketen bileşenler söküldü:
   - Gösterge LED’leri  
   - CH340 USB-UART dönüştürücü  
   - USB portu  
   - Dirençler  
4. UT681C PCB üzerinde sadece **zener diyotlar, LED’ler ve mod butonu** bırakıldı.
5. Bağlantılar bakır bobin teli ile yapıldı, PCB’ye montaj için delikler açıldı.
6. Kasa içine tam oturması için kesim ve düzenlemeler yapıldı.
7. Güç yönetimi için **MH-CD42 şarj/deşarj modülü** entegre edildi:
   - 5V sabit çıkışı sayesinde cihaz her zaman stabil çalışıyor.
8. Kasanın alt kısmına:
   - **Type-C portu**  
   - **Şarj göstergesi** için fiber ışık iletimi yapıldı.
9. Yazılıma eklenen özellikler:
   - Uzun basış ile uyku modu aç/kapa  
   - Kısa basış ile LED hız değiştirme (1s ↔ 0.5s)
10. Donanım güvenliği:
    - Alıcı ve verici birbirinden ayrıldığında cihaz açılıyor ve otomatik uykuya geçiyor.
    - Böylece taşınırken yanlışlıkla ayrılsa bile uyku modunda olduğu için cihazın enerjisi korunmuş oluyor.

---

## 🛠 Kullanılan Malzemeler
1. UNI-T UT681C kablo test cihazı  
2. Arduino Nano  
3. MH-CD42 şarj/deşarj modülü  
4. Type-C portu  
5. Lityum pil  
6. Fiber (şarj gösterge ışığı taşımak için)  
7. Bakır bobin teli  

---

##  ![IMG_20250831_150347](https://github.com/user-attachments/assets/fce84290-e190-4c9e-8c3a-7f10ebeb1456)
##  ![IMG_20250831_150339](https://github.com/user-attachments/assets/55bdfb16-946c-48dc-b793-8a889719ae5e)
##  ![IMG_20250830_123459](https://github.com/user-attachments/assets/769c97d3-be6d-4124-9076-5837fa43e2b6)
##  ![IMG_20250831_213651](https://github.com/user-attachments/assets/72914d1d-0c4a-4d12-aedd-de8fbb9f01c3)
##  ![IMG_20250831_150414](https://github.com/user-attachments/assets/36819618-3c05-4c95-93d2-514cb0e3bdf1)
##  ![IMG_20250831_204915](https://github.com/user-attachments/assets/84504100-6016-47e4-b7c8-ee1c64476365)
##  ![IMG_20250831_203842](https://github.com/user-attachments/assets/548dd420-b20f-487c-b1a1-fda45936c00d)
##  ![IMG_20250831_203809](https://github.com/user-attachments/assets/af79136e-89d0-419e-ac39-59f7315fdb22)
##  ![IMG_20250831_203801](https://github.com/user-attachments/assets/c3bbfa68-63fc-40fa-9301-b70d46770332)
##  ![IMG_20250831_150355](https://github.com/user-attachments/assets/7c9720a8-e3ea-4078-b39c-61f0ace63599)
---

## 
👉 (YouTube linkini buraya ekleyebilirsiniz.)

---

## ✨ Sonuç
- Cihaz çöpe gitmekten kurtarıldı ✅  
- Artık **şarjlı**, **daha enerji verimli** ve **modern** bir yapıya kavuştu.  
- Hem elektronik tamir süreci hem de güç optimizasyonu konusunda güzel bir örnek oldu.

---

## TAG
UNI-T UT681C Kablo Test Cihazı – Tamir ve Şarjlı Hale Getirme
UNIT UT681C cable Test Repair
unit hacking
unit hack

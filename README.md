# ⚖️ MSP430 ile Kablosuz Dijital Tartı Projesi

Bu proje, **MSP430G2553 mikrodenetleyicisi** ve **HX711 ADC entegresi** kullanılarak yük hücresinden (load cell) alınan ağırlık verilerini, **ESP8266 (ESP-01)** üzerinden lokal bir web sunucusuna kablosuz (Wi-Fi) aktaran ve anlık takip sağlayan bir IoT dijital tartı sistemidir.

---

## 📌 Proje Mantığı ve Çalışma Akışı

Sistem, donanımsal sinyal işlemeden web arayüzündeki görselleştirmeye kadar 4 ana aşamadan oluşur:

1. **Hassas Ölçüm (Donanım):** 1 kg kapasiteli yük hücresi üzerine binen yük, **HX711 24-bit ADC entegresi** tarafından okunarak dijital forma dönüştürülür.
2. **Sinyal İşleme (Gömülü Yazılım):** MSP430G2553 mikrodenetleyicisi ham veriyi alır, `OFFSET` ve `SCALE_FACTOR` kalibrasyon lojiğini uygulayarak ağırlığı gram cinsinden doğrular.
3. **Kablosuz İletişim (Network):** MSP430, doğrulanan ağırlık paketini UART seri haberleşme üzerinden **ESP8266 (ESP-01)** modülüne iletir. Modül, yerel Wi-Fi ağına bağlanarak veriyi HTTP POST isteği ile sunucuya fırlatır.
4. **Dashboard (Web Sunucu):** Python/Flask tabanlı backend servisi gelen post isteklerini yakalar ve web arayüzünde veriyi 1 saniyede bir otomatik yenileyerek canlı olarak ekrana basar.

---

## ⚙️ Sistem Mimarisi ve Blok Diyagramı

<p align="center">
  <img width="550" alt="Sistem Blok Diyagramı" src="https://github.com/user-attachments/assets/702f74fa-c1e0-4e58-b94b-7acee06d3378" />
</p>

---

## 🔩 Kullanılan Teknolojiler

### Donanım Katmanı
- **MSP430G2553:** Ana denetleyici; sensör okuma, UART paketleme ve zamanlama lojiğini yürütür.
- **HX711 Modülü:** Sinyal yükseltici ve 24-bit yüksek hassasiyetli ADC.
- **ESP-01 (ESP8266):** Wi-Fi tabanlı kablosuz iletişim modülü.
- **CH340 USB-TTL:** Seri haberleşme hattını izleme ve hata ayıklama (PuTTY) aracı.
- **Özel Güç Kaynağı:** Wi-Fi modülünün ani akım dalgalanmalarını filtreleyen, 220V AC'yi doğrultup stabil 3.3V DC sağlayan el yapımı regüle kartı.

### Yazılım Katmanı
- **MSP430 Firmware:** Gömülü C Dili (Code Composer Studio).
- **ESP8266 Firmware:** C++ / Arduino IDE.
- **Web Sunucusu:** Python, Flask Framework (VS Code).

---

## 📸 Proje Görselleri ve Tasarımlar

### 🛠️ Devre Şeması ve PCB Tasarımı
Sistemin Altium Designer / EasyEDA ortamında çizilen şematik diyagramı, yolları optimize edilmiş 2D PCB baskı tasarımı ve 3D modellemesi:

| 🔌 Şematik Devre Şeması | 🎛️ 2D PCB Baskı Yolları |
| --- | --- |
| <img width="400" alt="Şematik Devre Şeması" src="https://github.com/user-attachments/assets/449bba58-5915-4be6-b8a0-7a35d62906b3" /> | <img width="400" alt="2D PCB Tasarımı" src="https://github.com/user-attachments/assets/d4fc297f-7de1-41d8-8a17-92c761b8707b" /> |

| 🧊 3D Kart Modellemesi | 📄 PCB Baskı Kağıdı Çıktısı |
| --- | --- |
| <img width="400" alt="3D Modellenmiş PCB" src="https://github.com/user-attachments/assets/60d45232-76f0-49d0-822e-35cffabbdf5c" /> | <img width="400" alt="Baskı Devre Çıktısı" src="https://github.com/user-attachments/assets/0bf3078b-0a02-444f-9b2e-054cd8a11396" /> |

---

### 💻 Geliştirme ve Prototip Aşamaları
Sistemin breadboard üzerindeki ilk entegrasyon testi, üretilen PCB'nin ön ve arka yüz montaj aşamaları:

| 🔬 Breadboard Entegrasyon Testi | 🟢 Tamamlanmış Donanım (Ön Yüz) | 🔴 Tamamlanmış Donanım (Arka Yüz) |
| :---: | :---: | :---: |
| <img width="260" alt="Breadboard Entegrasyon Testi" src="https://github.com/user-attachments/assets/995b3b5d-2489-4186-ac0c-82b811f8ab39" /> | <img width="260" alt="Lehimlenmiş PCB Ön Yüz" src="https://github.com/user-attachments/assets/c3661b28-df7c-4442-8cc7-23ee735e1929" /> | <img width="260" alt="Lehimlenmiş PCB Arka Yüz" src="https://github.com/user-attachments/assets/402a6ed1-13e5-4e0c-b184-82c796741333" /> |

---

### 🌐 Canlı HTTP Web Dashboard
ESP8266 tarafından gönderilen ağırlık verisinin lokal ağ üzerinden (172.20.10.2:5000) Python backend terminalinde loglanması ve anlık olarak web arayüzüne basılması:

<p align="center">
  <img width="1386" height="779" alt="kjhbkjhb" src="https://github.com/user-attachments/assets/458647d5-6574-4ce4-8632-c354df7eded6" />
</p>

---

## 🗂️ Proje Yapısı
dijital-tarti-projesi/
├── msp430/      # MSP430 için gömülü C kodları
├── esp8266/     # ESP8266 için Wi-Fi ve HTTP bağlantı kodları
├── webserver/   # Python Flask tabanlı web sunucusu (app.py ve template dosyaları)
├── pcb/         # Devre şeması ve PCB tasarım dosyaları
└── README.md


---

## 🚀 Kurulum ve Çalıştırma
1. **Donanım Bağlantıları:** MSP430, HX711 ve ESP8266 bağlantılarını şemaya uygun şekilde tamamlayın. Cihaza harici güç kaynağından 3.3V verin.
2. **Firmware Yüklemesi:** `msp430/` klasöründeki kodları CCS ile MCU'ya, `esp8266/` kodlarını ise kendi Wi-Fi ağ bilgilerinizi girerek modüle flaşlayın.
3. **Sunucuyu Başlatma:** Web sunucu dizinine giderek Flask uygulamasını çalıştırın:
   ```bash
   cd webserver
   python app.py
Tarayıcınızdan sunucu adresine (örn: http://localhost:5000) giderek ağırlık verilerini canlı olarak izleyebilirsiniz.

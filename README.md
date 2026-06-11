# ⚖️ Dijital Tartı Projesi

Bu proje, **MSP430G2553 mikrodenetleyici** ve **HX711 ADC entegresi** kullanarak yük hücresinden (load cell) alınan hassas ağırlık verilerini, **ESP8266 (ESP-01)** Wi-Fi modülü üzerinden lokal bir web sunucusuna kablosuz ileten ve anlık izleme sağlayan bir IoT dijital tartı sistemidir.

---

## ✨ Özellikler

- 🔬 **Hassas Ölçüm:** MSP430 ile HX711 amplifikatöründen **24-bit çözünürlükte** ham veri okuma ve kalibrasyon lojiği.
- 📡 **Kablosuz Veri Aktarımı:** ESP8266 Wi-Fi modülü üzerinden UART haberleşmesi kullanılarak verilerin HTTP protokolüyle sunucuya post edilmesi.
- 🌐 **Canlı Web Dashboard:** Python / Flask tabanlı web sunucusu ile ağırlık verilerinin tarayıcı üzerinden 1 saniyede bir otomatik yenilenerek canlı izlenmesi.
- 🛠️ **Donanım Entegrasyonu:** Özel PCB tasarımı, harici güç kaynağı entegrasyonu ve fiziksel kalibrasyon testleri.

---

## 📸 Prototip ve Canlı Takip Ekranları

### 🛠️ Geliştirme Ortamı ve Fiziksel Prototip Testi
Sistemin breadboard üzerindeki donanım kurulumu, kalibrasyon süreçleri ve test masası üzerindeki aktif çalışma durumu (Su şişesi ile ağırlık doğrulama testi):

<p align="center">
<img width="2048" height="1152" alt="cnbhvc" src="https://github.com/user-attachments/assets/a612eaa8-9596-4304-9218-58be0dedca4e" /></p>

---

### 💻 Flask Web Sunucusu ve Veri Takip Arayüzü
Lokal ağdaki cihazdan (172.20.10.2) gelen ağırlık verilerinin Flask HTTP API üzerinden yakalanması, VS Code terminalinden loglanması ve web arayüzünde eş zamanlı gösterilmesi:

<p align="center">
  <img width="1386" height="779" alt="2" src="https://github.com/user-attachments/assets/87281a93-ac6f-413e-b9c3-1ca3db6f91f2" />
</p>

---

## 🔩 Donanım Bileşenleri

| Bileşen | Açıklama / Görevi |
|--------|----------|
| **MSP430G2553** | Ana mikrodenetleyici (MCU). Sensör okumasını ve UART paket yönetimini yapar. |
| **HX711** | 24-bit yüksek hassasiyetli yük hücresi amplifikatörü ve ADC entegresi. |
| **Load Cell (Yük Hücresi)** | 1 kg kapasiteli ağırlık sensörü. |
| **ESP-01 (ESP8266)** | Sunucu ile kablosuz haberleşmeyi sağlayan Wi-Fi modülü. |
| **Harici Güç Kaynağı** | Sistemin ve sensörlerin kararlı çalışması için regüleli 3.3V besleme. |

---

## 💻 Yazılım Mimarisi

| Katman | Kullanılan Teknoloji / Dil |
|--------|-----------|
| **MSP430 Firmware** | Gömülü C Dili, Code Composer Studio (CCS) |
| **ESP8266 Firmware** | AT Komutları / C++, Arduino IDE |
| **Web Server & Backend** | Python, Flask Framework (VS Code) |
| **Frontend UI** | HTML, CSS (1s anlık veri yenileme scripti) |

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
3. **Sunucuyu Başlatma:** Web sunucusu dizinine giderek Flask uygulamasını çalıştırın:
   ```bash
   cd webserver
   python app.py
Tarayıcınızdan sunucu adresine (örn: http://localhost:5000) giderek ağırlık verilerini canlı olarak izleyebilirsiniz.

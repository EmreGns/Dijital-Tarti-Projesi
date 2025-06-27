# Dijital Tartı Projesi

Bu proje, MSP430 mikrodenetleyici ve HX711 ADC entegresi kullanarak yük hücresinden alınan ağırlık verilerini kablosuz olarak ESP8266 modülü üzerinden bir web sunucusuna ileten dijital tartı sistemidir.

## Özellikler

- MSP430 mikrodenetleyici ile HX711’den 24 bit çözünürlükte ağırlık verisi okuma
- ESP8266 Wi-Fi modülü ile kablosuz veri aktarımı
- Flask tabanlı Python web sunucusu ile ağırlık verilerinin canlı izlenmesi
- PCB tasarımı ve prototip üretimi ile donanım-yazılım entegrasyonu

## Donanım Bileşenleri

- MSP430G2553 geliştirme kartı
- HX711 yük hücresi amplifikatörü
- 1 kg load cell (yük hücresi)
- ESP-01 (ESP8266) Wi-Fi modülü
- CH340 USB-TTL dönüştürücü
- Özelleştirilmiş PCB tasarımı

## Yazılım Bileşenleri

- MSP430 kodları (C dili, Code Composer Studio ortamında)
- ESP8266 kodları (Arduino IDE, HTTP veri gönderimi)
- Python/Flask web sunucusu (VS Code ortamında)

## Proje Yapısı

dijital-tarti-projesi/    
├── msp430/ # MSP430 için gömülü yazılım    
├── esp8266/ # ESP8266 için Wi-Fi kodları    
├── webserver/ # Python Flask tabanlı web sunucusu    
├── pcb/ # Devre şeması ve PCB tasarımı    
└── README.md


## Kullanım

1. MSP430 ve HX711 devresini kurun, MSP430’a ilgili kodları yükleyin. Karta güç kaynağı ile 3.3V sağlayın.
2. ESP8266’yı Wi-Fi bilgileriyle yapılandırarak HTTP gönderimi yapacak şekilde programlayın.
3. Python web sunucusunu çalıştırın:
    ```bash
    cd webserver
    python app.py
    ```
4. ESP8266’dan gelen veriler web arayüzünde canlı görüntülenecektir.





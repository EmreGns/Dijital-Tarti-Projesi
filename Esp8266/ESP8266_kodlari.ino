#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "Emre";
const char* password = "emregunes";
const char* serverUrl = "http://172.20.10.2:5000/data"; 
WiFiClient client; 
void setup() {
Serial.begin(9600);
delay(1000);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("WiFi bağlantısı tamamlandı.");
Serial.print("ESP IP adresi: ");
Serial.println(WiFi.localIP());
}
void loop() {
if (Serial.available()) {
String data = Serial.readStringUntil('\n');
data.trim();
19
if (WiFi.status() == WL_CONNECTED) {
HTTPClient http;
http.begin(client, serverUrl); 
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
String postData = "weight=" + data;
int httpResponseCode = http.POST(postData);
if (httpResponseCode > 0) {
Serial.print("Veri gönderildi: ");
Serial.println(data);
} else {
Serial.print("HTTP hata kodu: ");
Serial.println(httpResponseCode);
}
http.end();
}
delay(1000);
}
}

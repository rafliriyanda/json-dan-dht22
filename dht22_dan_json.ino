#include <DHT.h>
#include <ArduinoJson.h>

float sensor3,sensor4;
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  while (!Serial) continue;
  StaticJsonDocument<200> doc;
  sensor3 = dht.readHumidity();
  sensor4= dht.readTemperature();
  doc["sensor3"] =sensor3;
  doc["sensor4"] =sensor4;
  serializeJson(doc, Serial);
  Serial.println();
  delay(1000);
}
  

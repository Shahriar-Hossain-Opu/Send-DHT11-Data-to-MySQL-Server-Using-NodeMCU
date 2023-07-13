#include "DHT.h"
#include <ESP8266WiFi.h>

#define DHTPIN D5
#define DHTTYPE DHT21
DHT dht(DHTPIN,DHTTYPE);

float humidityData;
float temperatureData;

const char* ssid = "bicu";
const char* password = "12345678";
char server[] = "192.168.167.29"; 

WiFiClient client;    

void setup()
{
 Serial.begin(115200);
  delay(10);
  dht.begin();
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
 }

void loop()
{ 
  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature(); 
  Serial.print(humidityData);

     if (client.connect(server, 80)) {
    client.print("GET /testcode/insert.php?h=");
    client.print(humidityData);
    client.print("&t=");
    client.print(temperatureData);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 192.168.167.29");
    client.println("Connection: close");
    client.println();
  } else Serial.println("connection failed");

 delay(1000);
}

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
const char ssid[] = "INDONESIA1";
const char pass[] = "ridhoarif123";
const char server[] = "http://192.168.100.10/project_iot/api/api_suhuruang.php";
const char postServer[] = "http://192.168.100.10/project_iot/api/api_suhutubuh.php";
WiFiClient client;
String data = "";
void getData();
void postData();
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() == WL_CONNECTED) {
    delay(500);
    //Serial.println("Connecting to wifi");
  }
  /*Serial.println("");
  Serial.println("Wifi Terhubunng");
  Serial.println(WiFi.localIP());*/
}

void loop() {
  //postData();
  
  while(Serial.available() > 0)
  {
    char c = Serial.read();
    data = data + c;
  }
  if(data != "")
  {
    Serial.print(data);
  }
}
bool isConnected()
{
  return (WiFi.status() == WL_CONNECTED) ? true : false;
}
String dataSerial()
{
  String a = "";
  String data = "";
  while(Serial.available() > 0)
  {
    char c = Serial.read();
    a += c;
  }
  if(a == "1")
  {
    data = "suhu=36";
  } 
  return data;
}
void postData()
{
  String data = "";
  if(isConnected())
  {
    if(dataSerial() != "")
    {
      while(Serial.available() > 0)
      {
        char c = Serial.read();
        data += c;
      }
      if(data != "")
      {
        HTTPClient http;
        http.begin(client, postServer);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        int kode = http.POST(data);
        if(kode > 0)
        {
          Serial.println(kode);
        }
      } else {
        Serial.println("error");
      }
    }
  }
}
void getData()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(client, server);
    int code = http.GET();
    if(code > 0)
    {
      String payload = http.getString();
      Serial.println(code); // Cetak kode status HTTP
      Serial.println(payload); // Cetak data yang diambil dari server
    } else {
      Serial.println("Error Http Request");
    }
  }
  delay(1500);
}

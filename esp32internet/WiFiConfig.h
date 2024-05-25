#include "WiFiType.h"
#include <WiFi.h>
const char ssid[] = "INDONESIA1";
const char pass[] = "ridhoarif123";
bool isWifiConnected();
void connectWifi()
{
  WiFi.begin(ssid, pass);
  while(!(isWifiConnected()))
  {
    delay(1000);
    Serial.print("Sedang melakukan koneksi ke ");
    Serial.println(ssid);
  }
  Serial.print("Connected To : ");
  Serial.println(ssid);
  Serial.print("IP Anda : ");
  Serial.print(WiFi.localIP());
}
bool isWifiConnected()
{
  return (WiFi.status() == WL_CONNECTED) ? true : false;
}
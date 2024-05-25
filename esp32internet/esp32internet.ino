#include <SoftwareSerial.h>
#include "WiFiConfig.h"
#include "HttpReq.h"
SoftwareSerial uno(26, 25); //RX TX
String data = "";
void serialData();
void setup() {
  Serial.begin(9600);
  uno.begin(9600);
  connectWifi();
}

void loop() {
  serialData();
}
void serialData()
{
  while(uno.available() > 0)
  {
    char c = uno.read();
    data = data + c;
  }
  if(data != "")
  {
    Serial.println(data);
    uno.println(postDataSuhu(data));
  }
  data = "";
  delay(1000);
}

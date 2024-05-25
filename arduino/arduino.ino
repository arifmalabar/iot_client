#include <SoftwareSerial.h>
SoftwareSerial esp(3, 2); //RX TX
void setup() {
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  while(Serial.available() > 0)
  {
    if(Serial.read() == 49)
    {
      esp.print("suhu=36");
    }
  }
  delay(500);
  fromEsp();
}
String fromEsp(){
  String datafromesp = "";
  while(esp.available() > 0)
  {
    char c = esp.read();
    datafromesp = datafromesp + c;
  }
  if(datafromesp != "")
  {
    Serial.println(datafromesp);
  }
  return datafromesp;
}

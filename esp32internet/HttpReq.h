#include <HTTPClient.h>
const char ENDPOINT_SUHU[] = "http://192.168.100.10/project_iot/api/api_suhutubuh.php";

int postDataSuhu(String data)
{
  int responsecode = 0;
  if(isWifiConnected())
  {
    HTTPClient http;
    http.begin(ENDPOINT_SUHU);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    responsecode = http.POST(data);
    http.end();
  } else {
    
  }
  return responsecode;
}
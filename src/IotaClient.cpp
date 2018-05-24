#include "Arduino.h"
#include "IotaClient.h"
#include "external/Morse/Morse.h"
// #include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>


String _host;
String _port;


IotaClient::IotaClient(String host, String port)
{
  _host = host;
  _port = _port;

  Morse morse(2);

  Serial.print(host);
  Serial.print(":");
  Serial.println(port);

  //Maybe this needs to take an ESP client object?
}

void IotaClient::testRequest(WiFiClientSecure* client) {
  String url = "/";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client->print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client->connected()) {
    String line = client->readStringUntil('\n');
    if (line == "\r") {
      Serial.println(line);
      Serial.println("headers received");
      break;
    }
  }
  String line = client->readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}



// void IotaClient::testRequest(HTTPClient* http) {
//   //  HTTPClient http;
//   Serial.print("[HTTP] begin...\n");
//   // configure traged server and url
//   //http.begin("https://192.168.1.12/test.html", "7a 9c f4 db 40 d3 62 5a 6e 21 bc 5c cc 66 c8 3e a1 45 59 38"); //HTTPS

//   http->begin(_host); //HTTP

//   Serial.print("[HTTP] GET...\n");
//   // start connection and send HTTP header
//   int httpCode = http->GET();

//   // httpCode will be negative on error
//   if(httpCode > 0) {
//       // HTTP header has been send and Server response header has been handled
//       Serial.printf("[HTTP] GET... code: %d\n", httpCode);

//       // file found at server
//       if(httpCode == HTTP_CODE_OK) {
//           String payload = http->getString();
//           Serial.println(payload);
//       }
//   } else {
//       Serial.printf("[HTTP] GET... failed, error: %s\n", http->errorToString(httpCode).c_str());
//   }

//   http->end();

// }
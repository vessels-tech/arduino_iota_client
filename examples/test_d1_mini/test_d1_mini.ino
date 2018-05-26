#include <Arduino.h>
#include <IotaClient.h>

String host = "https://testnet140.tangle.works";
String httpsPort = 443;

IotaClient iota_client(host, httpsPort);

void setup() {
  Serial.begin(9600);
  Serial.println("HELLO IOTA");

  iota_client.testAddress();
}

void loop() {  
}

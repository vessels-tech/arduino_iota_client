#include "Arduino.h"
#include "IotaClient.h"
#include "external/Morse/Morse.h"
// #include <ESP8266HTTPClient.h>
// #include <WiFiClientSecure.h>

#ifdef __cplusplus
extern "C"
{
#endif

// C header here
#include "external/iota-c-light-wallet/src/iota/addresses.h"
#include "external/iota-c-light-wallet/src/iota/conversion.h"
#include "external/iota-c-light-wallet/src/iota/transfers.h"
// #include "user_interface.h"


#ifdef __cplusplus
}
#endif


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

void IotaClient::testAddress() {
  unsigned char address[81];
  // unsigned char address[] = "MZAVTZUNZ9EUWGYCSCGLSTONFRFISEWBOMXBIFNFJAGWTOBBDXMJ9KRNPJLJXWCYGEGMYDAAIWOCRHFTZ";
  char seedChars[] = "THISISABADSEED999";
  unsigned char seedBytes[48];
  chars_to_bytes(seedChars, seedBytes, 81);
  
  //This is causing a crash :(
  //perhaps because it's trying to do POW?
  get_public_addr(seedBytes, 0, 2, address);
  Serial.print("address is: ");
  Serial.println((char *)address);

  char charAddress[81];
  bytes_to_chars(address, charAddress, 48);

  Serial.print("charAddress is: ");
  Serial.println((char *)charAddress);
  //WARNING - I think this didn't get processed properly...
}

/**
 * prepareTransfers
 * attachToTangle (external shim?)
 * broadcast and store transactions locally?
 */
void IotaClient::sendTransfer() {
  Serial.println("sendTransfer");
  char *seed = "THISISABADSEED999"; // 81 ternary characters
  char address_one[82] = {0};
  char address_two[82] = {0};
  char *tag = "IOTAONARDUINO999"; //27 ternary characters

  //Define the output array, where the coins must go to.
  TX_OUTPUT output_txs[] = {{"ANADDRESS", 10000, "THISISAMESSAGE", "TTAG"}}; //ANADDRESS => 81 ternary characters
  // TX_OUTPUT output_txs[1];

  //Define the input array. Where the coins come from
  // TX_INPUT input_txs[] = {{4, 10000}};
  TX_INPUT input_txs[0];


  //Define the transaction chars array. The char trytes will saved in this array. (base-27 encoded)
  char transaction_chars[10][2673];
  // char transaction_bytes[10][1584];
  //Get all raw transaction trytes. Will saved in transaction_chars
  create_transfer_chars(seed, 2, output_txs, 1, input_txs, 0, transaction_chars);
  // create_transfer_bytes(seed, 2, output_txs, 1, input_txs, 0, transaction_bytes);

  Serial.print("transaction_chars are:");
  Serial.println((char *)transaction_chars);
  

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
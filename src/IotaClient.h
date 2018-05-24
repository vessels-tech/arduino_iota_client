#ifndef iota_client_h
#define iota_client_h

#include "Arduino.h"
#include "IotaClient.h"

//This must also be in the libraries folder!
// #include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>



class IotaClient {
  public:
    IotaClient(String host, String port);
    void testRequest(WiFiClientSecure* client);

  private:
    int _pin;
};

#endif
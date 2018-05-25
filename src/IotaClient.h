#ifndef iota_client_h
#define iota_client_h

#include "Arduino.h"
#include "IotaClient.h"
#include "external/iota-c-light-wallet/src/main.h"

//This must also be in the libraries folder!
// #include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

#ifdef __cplusplus
extern "C"
{
#endif

// C header here
#include "external/iota-c-light-wallet/src/iota/addresses.h"
#include "external/iota-c-light-wallet/src/iota/conversion.h"

#ifdef __cplusplus
}
#endif



class IotaClient {
  public:
    IotaClient(String host, String port);
    void testRequest(WiFiClientSecure* client);
    void sendTransfer();
    void testAddress();

  private:
    int _pin;
};

#endif
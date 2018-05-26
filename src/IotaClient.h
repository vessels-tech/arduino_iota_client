#ifndef iota_client_h
#define iota_client_h

#include "Arduino.h"
#include "IotaClient.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "external/iota-c-light-wallet/src/main.h"
#include "external/iota-c-light-wallet/src/iota/addresses.h"
#include "external/iota-c-light-wallet/src/iota/conversion.h"

#ifdef __cplusplus
}
#endif

class IotaClient
{
public:
  IotaClient(String host, String port);
  void testAddress();

private:
};

#endif
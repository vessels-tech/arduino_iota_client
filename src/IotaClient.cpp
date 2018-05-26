#include "Arduino.h"
#include "IotaClient.h"

#ifdef __cplusplus
extern "C"
{
#endif

// C header here
#include "external/iota-c-light-wallet/src/iota/addresses.h"
#include "external/iota-c-light-wallet/src/iota/conversion.h"
#include "external/iota-c-light-wallet/src/iota/transfers.h"

#ifdef __cplusplus
}
#endif

String _host;
String _port;

IotaClient::IotaClient(String host, String port)
{
  _host = host;
  _port = _port;
}

void IotaClient::testAddress()
{
  unsigned char address[81];
  char seedChars[] = "DONTEVERUSETHISSEED999";
  unsigned char seedBytes[48];
  chars_to_bytes(seedChars, seedBytes, 81);

  get_public_addr(seedBytes, 0, 2, address);
  char charAddress[81];
  bytes_to_chars(address, charAddress, 48);

  Serial.print("charAddress is: ");
  Serial.println((char *)charAddress);
}
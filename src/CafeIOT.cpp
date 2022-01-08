#include "CafeIOT.h"
WiFiClient client;


void CafeIOT::connect(const char* host, const uint16_t port)
{
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  while (!client.connect(host, port))
  {
    delay(500);
    Serial.print(".");
  }
}

void CafeIOT::reconnect(const char* host, const uint16_t port)
{
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  while (!client.connect(host, port))
  {
    delay(500);
    Serial.print(".");
  }
}
void CafeIOT::send(String Input)
{

  String A = Input + '\r' + '\n';

  client.print(A);
}

void CafeIOT::authentication(String Token)
{
  DynamicJsonDocument doc(1536);
  doc["Token"] = Token;
  String Output;
  serializeJson(doc, Output);
  Serial.print("Send to server:   ");
  Serial.println(Output);
  String A = Output + '\r' + '\n';

  client.print(A);
}

bool CafeIOT::status()
{
  if (client.connected())
  {
    return true;
  }
  else if (!client.connected())
  {
    return false;
  }
}

String CafeIOT::receive()
{

  String Recieve = (client.readStringUntil('\n'));
  return Recieve;
}

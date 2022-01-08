#pragma once
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <ArduinoJson.h>
extern WiFiClient client;


class CafeIOT
{
  public:
    bool status();
    String receive();
    void send(String Input);
    void authentication(String Token);
    void connect(const char* host, const uint16_t port);
    void reconnect(const char* host, const uint16_t port);

};

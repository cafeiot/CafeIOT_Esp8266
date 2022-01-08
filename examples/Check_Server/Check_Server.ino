#include <CafeIOT.h>
#define Token  "enter your token here"

const char* ssid = "wifi ssid";
const char* password = "wifi password";
CafeIOT CI;



void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  CI.connect("server.cafeiot.com" , 2323);   //Enter a host address and port
  CI.authentication(Token);
}

void loop() {

}

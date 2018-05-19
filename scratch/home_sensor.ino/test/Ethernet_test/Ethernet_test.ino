#include <Ethernet.h>
#include <SPI.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,10,80 };
byte server[] = { 192, 168, 10, 100 }; // Google

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  delay(1000);
  Serial.println("connecting...");

  if (client.connect(server, 25525)) {
    Serial.println("connected");
  } else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    //char c = client.read();
    //Serial.print(c);
    ;
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    //for(;;)
    //  ;
  }
  delay(1000);
}

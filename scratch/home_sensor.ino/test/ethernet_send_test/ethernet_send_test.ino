#include <Ethernet.h>
#include <SPI.h>
#include <String.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,10,80 };
byte server[] = { 192, 168, 10, 100 }; // My Server.

EthernetClient client;

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);

  delay(1000);

  Serial.println("connecting...");
  //Serial.println(client.connect(server, 25525));
  
  if (client.connect(server, 25525)) {
    //Serial.println("connected");
    //client.println("GET /search?q=arduino HTTP/1.0");
    //client.println();
    //Serial.println(Ethernet.localIP());
  } else {
    Serial.println("connection failed");
  }
}

void loop() {
   String str1 = "SENSOR:";
   String str2 = "DATA:";
   String str3 = ",";
  String str4 = "A";
  int data = 123;

  String temp;
  temp = String(str1 + str4);
  temp = String(temp + str3);
  temp = String(temp + str2);
  temp = String(temp + data);

  //char t[20];
  // temp.toCharArray(t);
  
  // client.write(t);
  char t[100];
  temp.toCharArray(t, 100);
  Serial.println(t);
  delay(5000);

}


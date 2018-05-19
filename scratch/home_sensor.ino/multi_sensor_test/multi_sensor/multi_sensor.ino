#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <SPI.h>
#include <String.h>

#define A 0
#define B 1
#define C 2
#define D 3
//#define E 4
//#define F 5
//#define G 6
#define DUR 10000 // Duration.

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 10, 80 };
byte server[] = { 192, 168, 10, 100 }; // My Server.
int port = 5000;

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
}

float read_sensor(int sen_num){ 
  //return analogRead(sen_num)*5/1024;
  randomSeed(analogRead(0));
  long readNumber = random(300) + random(50);
  return (readNumber + random(10));
}


String string_merger(int sensorName, float data){
  // Value tabel.
  // A  #Analog pin 0
  // B  #Analog pin 1
  // C  #Analog pin 2
  // D  #Analog pin 3
  // E  #Analog pin 4
  // F  #Analog pin 5
  // G  #Analog pin 6
  String str1 = "SENSOR:";
  String str2 = "DATA:";
  String str3 = ",";
  String str4;
  switch(sensorName){
    case 0:
      str4 = "A";
    case 1:
      str4 = "B";
    case 2:
      str4 = "C";
    case 3:
      str4 = "D";
    case 4:
      str4 = "E";
    case 5:
      str4 = "F";
    case 6:
      str4 = "G";
    default:
      str4 = "A";
      //Serial.println("Sensor number is out of range.");
  }

  // String merger.
  String temp;
  temp = String(str1 + str4);       // SENSOE:A
  temp = String(temp + str3);       // SENSOR:A,
  temp = String(temp + str2);       // SENSOR:A,DATA:
  temp = String(temp + data);       // SENSOR:A,DATA:20.8

  return temp;
}

void send_data(char t[]){
  EthernetClient client;
  if(Ethernet.begin(mac) == 0){
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  Serial.println(Ethernet.localIP()); //debug
  delay(1000);
  Serial.println("connecting...");

  if(client.connect(server, port)){
    Serial.println("connected");
  } else {
    Serial.println("connection failed");
  }
  
  client.write(t);
  Serial.println(t);  // debug.
  client.stop();
  
  Serial.println("Connection close.");  // debug.
}

void loop(){
  int count = 0;
  
  while(counr++){
  // Set sensor name.
  int sen_num  = A;
  int sen_num2 = B;
  int sen_num3 = C;
  int sen_num4 = D;

  // Read analog device.
  float data = read_sensor(sen_num);
  float data2 = read_sensor(sen_num2);
  float data3 = read_sensor(sen_num3);
  float data4 = read_sensor(sen_num4);

  // Make string for send data.
  String temp = string_merger(sen_num, data);
  String temp2 = string_merger(sen_num, data2);
  String temp3 = string_merger(sen_num, data3);
  String temp4 = string_merger(sen_num, data4);
  
  // Convert string to char array.
  char t[100];
  char t2[100];
  char t3[100];
  char t4[100];
  temp.toCharArray(t, 100);
  send_data(t);
  Serial.println(t);
  temp2.toCharArray(t2, 100);
  send_data(t2);
  Serial.println(t2);
  temp3.toCharArray(t3, 100);
  send_data(t3);
  Serial.println(t3);
  temp4.toCharArray(t4, 100);
  send_data(t4);
  Serial.println(t4);
    // Send duration.
  
  delay(DUR);    
  }

}

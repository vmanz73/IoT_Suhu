#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 
#define RX 9
#define TX 10
String AP = "x";       // CHANGE ME
String PASS = "x"; // CHANGE ME
String HOST = "192.168.43.155";
String PORT = "80";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
SoftwareSerial esp8266(RX,TX);
DHT dht(DHTPIN, DHTTYPE); 
 
void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  dht.begin();
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
}
void loop() {
 getSensorData();
}
void database(String data){

 sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(data.length()+4),4,">");
 esp8266.println(data);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
  
}
void getSensorData(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
   String getData = "GET /ard/?suhu="+ String (t) + "&kelem=" + String (h); 
   Serial.println(getData);
 database(getData);
  
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("Send");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }

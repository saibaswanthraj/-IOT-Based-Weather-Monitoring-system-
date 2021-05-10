#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

WiFiClient client;
WiFiServer server(80);

SoftwareSerial mySerial (D1, D2);

String host = "www.aapkaman.in";
int httpPort = 80;
String url1 = "/humidity.php?humidity=";
String url3 = "/temperature.php?temperature=";
String url2 = "/intesity.php?intensity=";

HTTPClient http;

void setup() {

     Serial.begin(115200);
     mySerial.begin(9600);
    WiFi.begin("note5A", "12345678");
    //Serial.println();
    while(WiFi.status() != WL_CONNECTED){
      Serial.println("..");
      delay(200);
    }
    Serial.println();
    Serial.println("NodeMCU is connected");
    Serial.println(WiFi.localIP());
    
    //server.begin();
}
void loop(){
  String msg = mySerial.readStringUntil('\n');
  //int msg = 70;
  msg.trim();
  String link1 = url1 + msg;
  http.begin(host,httpPort,link1);
  int httpCode = http.GET();
  Serial.println("Humidity: " + msg);
  Serial.println(httpCode);
  //delay(30);


String temp = mySerial.readStringUntil('\n');
  //int msg = 70;
  temp.trim();
  String link3 = url3 + temp;
  http.begin(host,httpPort,link3);
  int httpCodet = http.GET();
  Serial.println("Temperature: " + temp);
  Serial.println(httpCodet);
 // delay(300);

  
 String msh = mySerial.readStringUntil('\n');
 msh.trim();
 //Serial.println("Humidity: " + msh);
  Serial.println("Light intensity: " + msh);

  String link2 = url2 + msh;
  http.begin(host,httpPort,link2);
  int httpCoded = http.GET();
  Serial.println(httpCoded);

  delay(10000);
  

 }

#include <SoftwareSerial.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include <dht.h>
//#include <Adafruit_BMP085.h>


#define DEBUG 0                                     // change value to 1 to enable debuging using serial monitor  
#define dht_pin A0                                  // defining pin A0 for DHT sensor
#define lightSensor A1                              // defining pin A1 as input pin for LDR voltage divider
SFE_BMP180 pressure;
 
#define ALTITUDE 305.0
dht DHT;
//Adafruit_BMP085 bmp;

void setup() {
 Serial.begin(9600);
 //Serial.println("REBOOT");
 
}


void loop() {
   DHT.read11(dht_pin);
    double humi = DHT.humidity;
    double temp = DHT.temperature;
  int lightIntensity = analogRead(lightSensor);
  
  Serial.println(String(humi));
  Serial.println(String(temp));
  Serial.println(String(lightIntensity));

  delay(10000);

}

/*
 *     Appendix_3-Temperature_and_Humidity_Detection.c
 *
 *    Created on: Jul 1, 2022
 *      Author: Abdelrhman Salah Moghazy
 */
#include <dht.h>
 dht DHT;
 #define DHT11_PIN 7
 void setup(){
lcd.begin(16, 2); 
Serial.begin(9600); 
} void loop(){
 int chk = DHT.read11(DHT11_PIN);
 Serial.print("Temperature = ");
 Serial.println(DHT.temperature); 
Serial.print("Humidity = "); 
Serial.println(DHT.humidity);
 delay(1000);
int chk = DHT.read11(DHT11_PIN);
 lcd.setCursor(0,0); 
lcd.print("Temp: "); 
lcd.print(DHT.temperature); 
lcd.print((char)223); 
lcd.print("C"); 
lcd.setCursor(0,1);
 lcd.print("Humidity: ");
 lcd.print(DHT.humidity);
 lcd.print("%"); 
delay(1000);
  }


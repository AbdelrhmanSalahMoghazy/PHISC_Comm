/*
 * Smart_Ieeigation_Control_System_code.c
 *
 *  Created on: Jun 27, 2022
 *      Author: ABDO MOGHAZY
 */


#include <LiquidCrystal.h>

int FirstSensorVal;
int SecondSensorVal;

#define FirstSoilSensorPIN  A0
#define SecondSoilSensorPIN A2

#define rs  12
#define en  11
#define d4  5
#define d5  4
#define d6  3
#define d7  2
#define v0  9
#define RELAY_PIN 8

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{pinMode(v0,OUTPUT);
analogWrite(v0,130);
  lcd.begin(16, 2);
  lcd.print("..Reading Data ...");
  delay(500);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN,1);
  //serial
  delay(2000);
}

void loop()
{
  FirstSensorVal = analogRead(FirstSoilSensorPIN);
  FirstSensorVal = map(FirstSensorVal, 550, 0, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Moisture 1 : ");
  lcd.print(FirstSensorVal);
  if  (FirstSensorVal < 0 )
  {
    lcd.print("pump is on");
    digitalWrite(RELAY_PIN, LOW); // turn on pump 5 seconds
    delay(10);

  }
  else
  {
     lcd.print("pump is off");
    digitalWrite(RELAY_PIN, HIGH);  // turn off pump 5 seconds
      delay(50);

  }

  SecondSensorVal = analogRead(SecondSoilSensorPIN);
  SecondSensorVal = map(SecondSensorVal, 550, 0, 0, 100);
  lcd.setCursor(0, 1);
  lcd.print("Moisture 2 : ");
  lcd.print(SecondSensorVal);
  if  (SecondSensorVal < 0 ) {
     lcd.print("pump is on");
    digitalWrite(RELAY_PIN, LOW); // turn on pump 5 seconds
    delay(5000);

  }
  else
  {
     lcd.print("pump is off");
    digitalWrite(RELAY_PIN, HIGH);  // turn off pump 5 seconds
     delay(100);

  }

  delay(10000);
  lcd.clear();
}

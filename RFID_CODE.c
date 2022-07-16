/*
 * RFID_CODE.c
 *
 *  Created on: Jul 7, 2022
 *      Author: Abdelrhman Moghazy
 */

/* --------------------------------------------------------------------------------------------------------------------
 * Designed PCB configuration
 * | 1   |  2  |  3   | 4  | 5  | 6  | 7  | 8  | 9  | 10 |   11    | 12  |  13  |  14  | 15  | 16  |   17   | 18 | 19 |
 * |-----|-----|------|----|----|----|----|----|----|----|---------|-----|------|------|-----|-----|--------|----|----|
 * | gnd | vcc | 3.3V | V0 | rs | en | d4 | d5 | d6 | d7 | sda(ss) | sck | mosi | miso | irq | rst | buzzer | tx | rx |
 * |-----|-----|------|----|----|----|----|----|----|----|---------|-----|------|------|-----|-----|--------|----|----|
 * | gnd | vcc | 3.3V | 2  | 3  | 8  | 4  | 5  | 6  | 7  |   10    | 13  |  11  |  12  |  -  |  9  |   A0   | Tx | Rx |
 * --------------------------------------------------------------------------------------------------------------------
 */

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Wire.h>


#define rs          3
#define d4          4
#define d5          5
#define d6          6
#define d7          7
#define en          8
#define RST_PIN     9          // Configurable, see typical pin layout above
#define SS_PIN      10         // Configurable, see typical pin layout above
#define mosi        11
#define miso      12
#define sck         13
#define BUZZER    A0  //  BUZZER PIN
#define LED_R     A1  //  RED_LED PIN
#define LED_G     A2  //  GREEN_LED PIN

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
String uid1 = "F3 62 11 08";
String uid2 = "32 D7 46 1E";
String uid3 = "99 92 84 83";
String uid4 = "29 42 95 83";
void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  lcd.begin(16,2);
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);

}
void loop()
{
  Serial.println("lcd :    Scan Tag    ");
  lcd.setCursor(3,0);
  lcd.print("SHOW YOUR");
  lcd.setCursor(4,1);
  lcd.print("ID CARD");
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.println("Message : ");
  lcd.clear();

  content.toUpperCase();
  if (content.substring(1) == uid1) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    Serial.println("Tag 01");
    Serial.println("Authorized access");
    lcd.setCursor(0,0);
    lcd.print("    ID = 001   ");
    lcd.setCursor(0,1);
    lcd.print(" Authorized ID ");
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print("Welcome");
    lcd.setCursor(0,1);

    lcd.print("Abdelrhman Salah");
  }



  else if (content.substring(1) == uid2) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    Serial.println("Tag 02");
    Serial.println("Authorized access");
    delay(3000);
  }

  else if (content.substring(1) == uid3) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    Serial.println("Tag 03");
    Serial.println("Authorized access");
    delay(3000);
  }

  /*else if (content.substring(1) == uid4) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Tag 04");
    lcd.setCursor(0,1);
    lcd.print("Authorized access");
    delay(3000);
    lcd.clear();
  }*/
  else   {
    Serial.println(" Access Denied");
    Serial.println("Unknown");
    Serial.println("Access Denied");

    lcd.setCursor(0,0);
    lcd.print("   UnKnown ID   ");
            //"                "
    lcd.setCursor(0,1);
    lcd.print("  Access Denied ");
                //"                "
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print("Try to contact");
            //"                "
    lcd.setCursor(0,1);

    lcd.print("Visitor Service");
  }
}


/*
 *     Smart_Home_05_01feb.ino
 *
 *    Created on: Feb 1, 2022
 *      Author: Abdelrhman Salah Moghazy
 */


/************************************************************************/
/************************   includes    *********************************/
/************************************************************************/
#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include<Servo.h>
#include"Smart_House_Config.h"
#include"LSTD_TYPES.h"

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/************************************************************************/
/***********************    keypad code part  *********************/
/************************************************************************/

s8 hexaKeys[ROWS][COLS] = {   
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},          //define the symbols on the buttons of the keypads
    {'*','0','#','D'}
};
u8 rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
u8 colPins[COLS] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad

/************************************************************************/
/************************************************************************/

u1 door = true;
u8 data_count = 0;
u8 Data[Password_Lenght];           // 6 is the number of chars it can hold + the null char = 7
u8 Master[Password_Lenght] = "111111";      //Change PASSWORD here

u8 customKey;
u8 local_itterator;
u8 u8_print;
Servo myservo;
u8 Irvalue;
/************************************************************************/
/************************************************************************/
#if (defined(AVR) || defined(ESP8266)) && !defined(AVR_ATmega2560)

SoftwareSerial mySerial(fngrPrntTx,fngrPrntRx);   //fingerprint pins

#else

#define mySerial Serial

#endif

/************************************************************************/
/************************************************************************/

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

/************************************************************************/
/***********************    SETUP     *****************************/
/************************************************************************/

void setup()
{
  lcd.begin(16, 2); //16*2 LCD screen
  //Serial.begin(baud_rate);
  //while (!Serial);
  delay(100);
  myservo.attach(ServoSignalPin);
  pinMode (IRSensorPin, INPUT);
  Serial.begin(9600);
  finger.begin(fngrPrntRate); // set the data rate for the sensor serial port
  delay(5);
  //Serial.println("enter your finger print");
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("PUT Y0UR F-PRINT");
  Serial.println("PUT Y0UR F-PRINT");
  
      myservo.write(0);
}

/************************************************************************/
/***********************    LOOP      *****************************/
/************************************************************************/
void loop()
{
  Irvalue = digitalRead (IRSensorPin);
  while (Irvalue == 0)
  {
    Serial.println("on");
    void_process();
  }
  lcd.clear();
}

/********************************************************************************/
/***************************  void_process()    *****************************/
/********************************************************************************/
void void_process()
{
  
  if (0==door)
  {
    customKey = customKeypad.getKey();

    

    if (customKey == '1')
    {

      lcd.clear();
      lcd.setCursor (3,0);
      lcd.print("L0CKING");
      
  Serial.println("locking");

      
      delay (700);
      lcd.setCursor (10,0);
      lcd.print(".");
      delay (800);
      lcd.setCursor (11,0);  
      lcd.print(".");
      delay (800);
      lcd.setCursor (12,0);
      lcd.print(".");
      delay (500);
      lcd.clear();
      delay (500);
      myservo.write(0);
      lcd.setCursor (5,0);
      lcd.print("L0CKED");
      Serial.println("locked");
      delay (1700);

      Irvalue = 1;
      door = 1;
    }

  }
  else Open();
}

/************************************************************************************/
/************************   getFingerprintID()    *****************************/
/************************************************************************************/
u8 getFingerprintID() 
{
  u8 u8_print = finger.getImage();
  if(u8_print == FINGERPRINT_OK)
  {
    Serial.println("Image taken");

  }
  else
  {
    Serial.println("put your fucckin finger again");
    return u8_print; 
  }

  u8_print = finger.image2Tz();
  if(u8_print == FINGERPRINT_OK)
  {
    Serial.println("Image converted");
  }
  else
  {
    Serial.println("Image not converted");
    return u8_print; 
  }
  u8_print = finger.fingerSearch();
  if (u8_print == FINGERPRINT_OK)
  {
    lcd.clear();
    lcd.print("matched");
    Serial.println("matched");
      
    delay(1000);
    local_itterator=0;

  } 
  else 
  {
    lcd.clear();
    lcd.print("not matched");
    Serial.println("not matched");
      
    delay(1000);
    return u8_print;

  }

  // found a match!
  lcd.clear();
  if((finger.fingerID==1)||(finger.fingerID==2)||(finger.fingerID==3))
  {
    lcd.print("welc0me saad"); delay(1000);
  }
  if((finger.fingerID==23))
  {
    lcd.print("welc0me Abd0"); delay(1000);
    
    Serial.println("welc0me Abd0");
  }
  //Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
  return u8_print;

}

/************************************************************************************/
/*******************************    clearData()   *****************************/
/************************************************************************************/
void clearData()
{
  while (data_count != 0)
  { // This can be used for any array size,
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}

/************************************************************************************/
/***********************************    Open()    *****************************/
/************************************************************************************/
void Open()
{
  lcd.setCursor(1, 0);
  lcd.print("INPUT PASSW0RD");
  
    Serial.println("INPUT PASSW0RD");

  customKey = customKeypad.getKey();
  
  if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
  {
    lcd.setCursor(0, 1); 
    
    Serial.println("customKey");
    lcd.print("*");     //To hide your PASSWORD, make sure its the same lenght as your password
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    //lcd.print(Data[data_count]);
  lcd.print("*");
  
    Serial.println("customKey");
    Serial.println(Data[data_count]);// print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }

  if (data_count == Password_Lenght - 1) // if the array index is equal to the number of expected chars, compare data to master
  {
    if (!strcmp(Data, Master)) // equal to (strcmp(Data, Master) == 0)   strcmp --> string compare
    {
      lcd.clear();
      lcd.print(" ACCESS");
      
    Serial.println("access");
      delay(1500);
      lcd.clear();
      for(local_itterator=1;local_itterator<=100 ;local_itterator++)
      {
        lcd.setCursor(0,0);
        lcd.print("enter fngerprint");
        
    Serial.println("enter fingrprnt");
        getFingerprintID();
        if(local_itterator==0)
          break;
      }  
      lcd.clear();
      lcd.print("d00r opened");
      
    Serial.println("door opened");
      myservo.write(85);
      delay(500);
      lcd.clear();
      lcd.print("press 1 t0 cl0se");
      
    Serial.println("press 1 to close");
      door = 0;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(1,0); 
      lcd.print("N0T ACCESS");
      
    Serial.println("not access");
      delay(1000);
      // myservo.write(0);
      door = 1;
    }
    clearData();
  }
}

/*
 * PSGCS_code.ino
 *
 *  Created on: Mar 20, 2022
 *      Author: Abdelrhman Moghazy
 */

#ifndef PSGCS_PSGCS_CONFIG_H_
#define PSGCS_PSGCS_CONFIG_H_



#include <Servo.h>
#include<LiquidCrystal.h>
#define rs 3
#define en 4
#define d4 8
#define d5 5
#define d6 6
#define d7 7
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define     SERVO_ENTERY  A3
#define     SERVO_EXIT    A2
#define     IR_ENTERY     A0
#define     IR_EXIT       A1

Servo ENTERY_GATE;
Servo EXIT_GATE;

#endif /* PSGCS_PSGCS_CONFIG_H_ */

/*
 * PSGCS_private.h
 *
 *  Created on: Mar 20, 2022
 *      Author: PC
 */

#ifndef PSGCS_PSGCS_PRIVATE_H_
#define PSGCS_PSGCS_PRIVATE_H_

u8 counter =0;

void PSGCS_VidOpenGate(u8 Copy_u8GateName)
{
  if (SERVO_ENTERY==Copy_u8GateName)
  {
    ENTERY_GATE.write(20);
  }
  else if (SERVO_EXIT==Copy_u8GateName)
  {
    EXIT_GATE.write(70);
  }
}

void PSGCS_VidCloseGate(u8 Copy_u8GateName)
{
  if (SERVO_ENTERY==Copy_u8GateName)
  {
    ENTERY_GATE.write(90);
  }
  else if (SERVO_EXIT==Copy_u8GateName)
  {
    EXIT_GATE.write(10);
  }
}


#endif /* PSGCS_PSGCS_PRIVATE_H_ */

/*
 * PSGC_program01_Moghazy_Mar27.ino
 *
 *  Created on: Mar 27, 2022
 *      Author: ABDO_MOGHAZY
 */
/*
 * LSTD_TYPES.h
 *
 *  Created on: Jan 21, 2022
 *      Author: ABDO_MOGHAZY
 */
#ifndef LSTD_TYPES_H_
#define LSTD_TYPES_H_


typedef enum{
  NOK,
  OK
}ErrorState;

typedef unsigned char   u8 ;
typedef signed char     s8 ;

typedef unsigned short int   u16 ;
typedef signed short int     s16 ;
typedef unsigned long int    u32 ;
typedef signed long int      s32 ;

typedef float   f32 ;
typedef double  f64 ;

#endif

 u8 Su8CarCount = 0;
void setup ()
{
  pinMode(IR_ENTERY,INPUT);
  pinMode(IR_EXIT,INPUT);

  pinMode(rs,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(d4,OUTPUT);
  pinMode(d5,OUTPUT);
  pinMode(d6,OUTPUT);
  pinMode(d7,OUTPUT);

  ENTERY_GATE.attach(SERVO_ENTERY);
  EXIT_GATE.attach(SERVO_EXIT);
  
  PSGCS_VidCloseGate(SERVO_EXIT);
  PSGCS_VidCloseGate(SERVO_ENTERY);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("PSGCS Initialize");
  lcd.setCursor(0,1);
  for(int i=0;i<16;i++)
  {
    lcd.print(".");
    delay(250);
  }
  lcd.clear();
  lcd.print("SMART GARAGE");
  lcd.setCursor(0,1);
  delay(3000);
  lcd.clear();
  PSGCS_VidCloseGate(SERVO_EXIT);
  PSGCS_VidCloseGate(SERVO_ENTERY);
}
void loop ()
{
    /*delay(2000);
    PSGCS_VidOpenGate(SERVO_EXIT);
    PSGCS_VidOpenGate(SERVO_ENTERY);
    delay(2000);
    PSGCS_VidCloseGate(SERVO_EXIT);
    PSGCS_VidCloseGate(SERVO_ENTERY);*/
  if(Su8CarCount<8&&Su8CarCount>0)
  {
    inn();
    out();
    delay(500);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cars inside = ");
    
    lcd.print(String(Su8CarCount));
  }
  else if (Su8CarCount<=0)
  {
    inn();
  }
  else if (Su8CarCount>=8)
  {
    
    lcd.clear();
    lcd.print("Sorry go away");
  }
}



void inn()
{
  if(200>analogRead(IR_ENTERY))
  {
    while(200>analogRead(IR_ENTERY))
    {
      PSGCS_VidOpenGate(SERVO_ENTERY);
    }
    delay(2000);

    PSGCS_VidCloseGate(SERVO_ENTERY);
    Su8CarCount++;
    
  }
  //PSGCS_VidCounter(Su8CarCount);
}
void out()
{
  if(200>analogRead(IR_EXIT))
  {
    while(200>analogRead(IR_EXIT))
    {

      PSGCS_VidOpenGate(SERVO_EXIT);
     
    }
    delay(2000);

    --Su8CarCount;
    PSGCS_VidCloseGate(SERVO_EXIT);
  }
}

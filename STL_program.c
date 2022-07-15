/*
 * STL_program.c
 * 
 *
 *  Created on: Mar 10, 2022
 *      Author: Abdo_Moghazy
 */


/************************  2digit seven Copy_u8DigitIDment counter 0->99  *****************************/
#define LED_G_R   10
#define LED_R_G   11
#define LED_Y_Y   12

#define  O 1
#define T 2

#define AO  2
#define BO  3
#define CO  4
#define DO  5

#define AT  6
#define BT  7
#define CT  8
#define DT  9


#include "LSTD_TYPES.h"
void DTL_VidDTL_VidSeven_segment_write(u8 Copy_u8DigitValue,u8 Copy_u8DigitID);

void setup()
{

}

void loop()
{
  for(u8 m=3;0<=m;m--)
  {
    for(u8 k=9;0<=k;k--)
    {
      if(m=3)
      {
        k=0;
      }
      DTL_VidSeven_segment_write(m,O);
      DTL_VidSeven_segment_write(k,T);
      digitalWrite(LED_G_R,1);
      digitalWrite(LED_Y_Y,0);
      digitalWrite(LED_R_G,0);
      delay(1000);
    }
  }

  for(int m=0;0<=m;m--)
  {
    for(int k=3;0<=k;k--)
    {
      DTL_VidSeven_segment_write(m,O);
      DTL_VidSeven_segment_write(k,T);
      digitalWrite(LED_G_R,0);
      digitalWrite(LED_Y_Y,1);
      digitalWrite(LED_R_G,0);
      delay(1000);
    }
  }

  for(int m=3;0<=m;m--)
  {
    for(int k=9;0<=k;k--)
    {
      if(m=3)
      {
        k=0;
      }
      DTL_VidSeven_segment_write(m,O);
      DTL_VidSeven_segment_write(k,T);
      digitalWrite(LED_G_R,0);
      digitalWrite(LED_Y_Y,0);
      digitalWrite(LED_R_G,1);
      delay(1000);
    }
  }
  for(int m=0;0<=m;m--)
  {
    for(int k=3;0<=k;k--)
    {
      DTL_VidSeven_segment_write(m,O);
      DTL_VidSeven_segment_write(k,T);
      digitalWrite(LED_G_R,0);
      digitalWrite(LED_Y_Y,1);
      digitalWrite(LED_R_G,0);
      delay(1000);
    }
  }

}

/*************************************************/

void DTL_VidSeven_segment_write(u8 Copy_u8DigitValue,u8 Copy_u8DigitID)
{
  if (O==Copy_u8DigitID)
  {
    switch (Copy_u8DigitValue)
    {
    case 0:
      digitalWrite(AO,LOW);
      digitalWrite(BO,LOW);
      digitalWrite(CO,LOW);
      digitalWrite(DO,LOW);
      break;
    case 1:
      digitalWrite(AO,HIGH);
      digitalWrite(BO,LOW);
      digitalWrite(CO,LOW);
      digitalWrite(DO,LOW);
      break;
    case 2:
      digitalWrite(AO,LOW);
      digitalWrite(BO,HIGH);
      digitalWrite(CO,LOW);
      digitalWrite(DO,LOW);
      break;
    case 3:
      digitalWrite(AO,HIGH);
      digitalWrite(BO,HIGH);
      digitalWrite(CO,LOW);
      digitalWrite(DO,LOW);
      break;
    case 4:
      digitalWrite(AO,LOW);
      digitalWrite(BO,LOW);
      digitalWrite(CO,HIGH);
      digitalWrite(DO,LOW);
      break;
    case 5:
      digitalWrite(AO,HIGH);
      digitalWrite(BO,LOW);
      digitalWrite(CO,HIGH);
      digitalWrite(DO,LOW);
      break;
    case 6:
      digitalWrite(AO,LOW);
      digitalWrite(BO,HIGH);
      digitalWrite(CO,HIGH);
      digitalWrite(DO,LOW);
      break;
    case 7:
      digitalWrite(AO,HIGH);
      digitalWrite(BO,HIGH);
      digitalWrite(CO,HIGH);
      digitalWrite(DO,LOW);
      break;
    case 8:
      digitalWrite(AO,LOW);
      digitalWrite(BO,LOW);
      digitalWrite(CO,LOW);
      digitalWrite(DO,HIGH);
      break;
    case 9:
      digitalWrite(AO,HIGH);
      digitalWrite(BO,LOW);
      digitalWrite(CO,LOW);
      digitalWrite(DO,HIGH);
      break;
    default:
      digitalWrite(AO,LOW);
      digitalWrite(BO,HIGH);
      digitalWrite(CO,HIGH);
      digitalWrite(DO,HIGH);
      break;
    }
  }
  else if (T==Copy_u8DigitID)
  {
    switch (Copy_u8DigitValue)
    {
    case 0:
      digitalWrite(AT,LOW);
      digitalWrite(BT,LOW);
      digitalWrite(CT,LOW);
      digitalWrite(DT,LOW);
      break;
    case 1:
      digitalWrite(AT,HIGH);
      digitalWrite(BT,LOW);
      digitalWrite(CT,LOW);
      digitalWrite(DT,LOW);
      break;
    case 2:
      digitalWrite(AT,LOW);
      digitalWrite(BT,HIGH);
      digitalWrite(CT,LOW);
      digitalWrite(DT,LOW);
      break;
    case 3:
      digitalWrite(AT,HIGH);
      digitalWrite(BT,HIGH);
      digitalWrite(CT,LOW);
      digitalWrite(DT,LOW);
      break;
    case 4:
      digitalWrite(AT,LOW);
      digitalWrite(BT,LOW);
      digitalWrite(CT,HIGH);
      digitalWrite(DT,LOW);
      break;
    case 5:
      digitalWrite(AT,HIGH);
      digitalWrite(BT,LOW);
      digitalWrite(CT,HIGH);
      digitalWrite(DT,LOW);
      break;
    case 6:
      digitalWrite(AT,LOW);
      digitalWrite(BT,HIGH);
      digitalWrite(CT,HIGH);
      digitalWrite(DT,LOW);
      break;
    case 7:
      digitalWrite(AT,HIGH);
      digitalWrite(BT,HIGH);
      digitalWrite(CT,HIGH);
      digitalWrite(DT,LOW);
      break;
    case 8:
      digitalWrite(AT,LOW);
      digitalWrite(BT,LOW);
      digitalWrite(CT,LOW);
      digitalWrite(DT,HIGH);
      break;
    case 9:
      digitalWrite(AT,HIGH);
      digitalWrite(BT,LOW);
      digitalWrite(CT,LOW);
      digitalWrite(DT,HIGH);
      break;
    default:
      digitalWrite(AT,LOW);
      digitalWrite(BT,HIGH);
      digitalWrite(CT,HIGH);
      digitalWrite(DT,HIGH);
      break;
    }
  }
}

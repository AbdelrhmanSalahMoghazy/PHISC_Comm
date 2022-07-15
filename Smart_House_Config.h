 
/*
 * Smart_House_Config.h
 *
 *  Created on: Feb 01, 2022
 *      Author: Abdelrhman Salah Moghazy
 */

#ifndef SMART_HOUSE_CONFIG_H_
#define SMART_HOUSE_CONFIG_H_

#define ServoSignalPin    10  /*connect to the Yellow wire of the Servo motor*/
#define Password_Lenght   7 			// Give enough room for six chars + NULL char
#define           rs      A5
#define	          en      A4
#define	          d4      A3
#define	          d5      A2
#define	          d6      A1
#define	          d7      A0
#define	         ROWS     4 			//four rows
#define          COLS     4 			//four columns
#define     baud_rate     9600
#define     fngrPrntRate  57600
#define     fngrPrntTx	  12  /*connect to the Yellow wire of the fingerprint sensor*/
#define     fngrPrntRx    13  /*connect to the White wire of the fingerprint sensor*/
#define     IRSensorPin   11  /*connect to the signal pin of the ir sensor*/ 
/*
rowPins 7:4 connect to the row pinouts of the keypad
colPins 3:0 connect to the column pinouts of the keypad
*/

#endif /* SMART_HOUSE_CONFIG_H_ */
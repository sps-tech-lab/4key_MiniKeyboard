/*
  ************************************************************************************
  * 4key MIni HID Keyboard
  * Date 2023 
  ************************************************************************************
*/
//Includes
#include "USBHIDKeyboard.h"
#include <WS2812.h>
#include <stdio.h>
#include <stdint.h>
#include "neo.h"
#include "led.h"
#include "buttons.h"

#ifndef USER_USB_RAM
#error "Require USB RAM, set: [Tools]->[USB Setting]->[USER CODEw/ 148b USB ram]"
#endif

//Peripherals
#define NEO_LED_PIN 34 

//Neo pixel on each key
// #define NUM_LEDS    4
// #define NUM_COLORS  3
// #define NUM_BYTES   NUM_LEDS*NUM_COLORS




//------------------------------------------------------------------------------------
void setup(){
  //Init peripherals
  USBInit();
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);

  pinMode(NEO_LED_PIN, OUTPUT);

  pinMode(DBG_LED_PIN, OUTPUT);  //DEV BOARD
}

//------------------------------------------------------------------------------------
void loop(){
  //Buttons
  BTN_Main();
  //Indication
  LED_Rainbow();
  //Time quant
  delay(1);
}
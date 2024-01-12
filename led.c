/*
  ************************************************************************************
  * Led custom indication patterns
  ************************************************************************************
*/
//Includes
#include "led.h"
#include "neo.h"
#include <Arduino.h>

uint8_t rainbow_speed = LED_RAINBOW_SPEED;

//Simple rainbow
uint8_t hue_1 = 0;
uint8_t hue_2 = 45;
uint8_t hue_3 = 90;
uint8_t hue_4 = 135;

void LED_Rainbow( void ){

  if( rainbow_speed != 0 ){
    rainbow_speed--;
    return;
  }

  //Rainbow test
  if( ++hue_1 > 191 ) hue_1 = 0;
  if( ++hue_2 > 191 ) hue_2 = 0;
  if( ++hue_3 > 191 ) hue_3 = 0;
  if( ++hue_4 > 191 ) hue_4 = 0;

  NEO_writeHue(0, hue_1, NEO_BRIGHT_LOW);
  NEO_writeHue(1, hue_2, NEO_BRIGHT_LOW);
  NEO_writeHue(2, hue_3,  NEO_BRIGHT_LOW); 
  NEO_writeHue(3, hue_4, NEO_BRIGHT_LOW);
  NEO_update();  

  rainbow_speed = LED_RAINBOW_SPEED;
}

void LED_DebugBlink( bool state ){
#if DEBUG_LED
  if( state == true ){
    digitalWrite(DBG_LED_PIN, 1);
  }else{
    digitalWrite(DBG_LED_PIN, 0);
  }
#endif
}

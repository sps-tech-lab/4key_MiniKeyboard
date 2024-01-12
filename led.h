/*
  ************************************************************************************
  * Led custom indication patterns
  ************************************************************************************
*/
//Includes
#include <stdint.h>
#include <stdbool.h>

//Config
#define DBG_LED_PIN       30  //DEV BOARD [!]
#define DEBUG_LED         1   //[1]ON/[0]OFF
#define LED_RAINBOW_SPEED 40  //Animation speed

//API
void LED_Rainbow( void );
void LED_DebugBlink( bool state );
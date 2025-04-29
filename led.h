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
#define LED_PATTERN_SPEED 40  //Animation speed
#define LED_FD_STEPS      100
#define LED_TR_STEPS      30

enum ld_patterns{ 
  LDP_RAINBOW   = 0,
  LDP_CYBERPUNK = 1,
  LDP_PORTAL    = 2,
  LDP_NOLIGHT   = 3,
};


//API
void LED_Main( void );
void LED_SetPattern( uint8_t index );
void LED_NextPattern( void );
void LED_DebugBlink( bool state );
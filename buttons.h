/*
  ************************************************************************************
  * Buttons processing
  ************************************************************************************
*/
//Includes
#include <stdint.h>
#include <stdbool.h>

//Config
#define BTN_DEBOUNCE_TIMEOUT 10

//Pin config
#define BUTTON1_PIN 15
#define BUTTON2_PIN 16
#define BUTTON3_PIN 17
#define BUTTON4_PIN 11

//Button struct
struct button_s{
  bool    press;
  bool    prev_state;
  uint8_t gpio;
  uint8_t debounce;
};

//API
void BTN_Main( void );
void BTN_test( void );
bool BTN_Processing( struct button_s *btn );
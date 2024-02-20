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
  bool    hold;
  bool    prev_state;
  uint8_t gpio;
  uint8_t debounce;
  uint8_t timer;
};

enum btn_press_t{ 
  BTN_NO_PRESS     = 0,
  BTN_SHORT_PRESS  = 1,
  BTN_LONG_PRESS   = 2,
};

//API
void BTN_Main( void );
void BTN_test( void );
enum btn_press_t BTN_Processing( struct button_s *btn );
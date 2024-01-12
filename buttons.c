/*
  ************************************************************************************
  * Buttons processing
  ************************************************************************************
*/
//Includes
#include "USBHIDKeyboard.h"
#include "buttons.h"
#include "led.h"
#include <Arduino.h>


//Buttons
struct button_s btn1 = { .gpio = BUTTON1_PIN };
struct button_s btn2 = { .gpio = BUTTON2_PIN };
struct button_s btn3 = { .gpio = BUTTON3_PIN };
struct button_s btn4 = { .gpio = BUTTON4_PIN };


bool BTN_Processing( struct button_s *btn ){
  //Debounce
  if( btn->debounce != 0 ){
    btn->debounce--;
    return false;
  }
  //Processing
  btn->press = (bool)!digitalRead(btn->gpio);
  if( btn->prev_state != btn->press ){
    btn->prev_state = btn->press;
    if( btn->press ){
      LED_DebugBlink(false);
      return true;
    } else {
      Keyboard_releaseAll();
      LED_DebugBlink(true);
    }
    btn->debounce = BTN_DEBOUNCE_TIMEOUT;
  }
  return false;
}

void BTN_Main( void ){
  if( BTN_Processing( &btn4 ) == true ){
    //Sequence 'ä'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_8);
    Keyboard_release(KEY_LEFT_ALT);
  }
  if( BTN_Processing( &btn3 ) == true ){
    //Sequence 'ö'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_4);
    Keyboard_click(KEYPAD_6);
    Keyboard_release(KEY_LEFT_ALT);
  }
  if( BTN_Processing( &btn2 ) == true ){
    //Sequence 'ü'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_5);
    Keyboard_click(KEYPAD_2);
    Keyboard_release(KEY_LEFT_ALT);
  }
  if( BTN_Processing( &btn1 ) == true ){
    //Sequence 'ß'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_3);
    Keyboard_release(KEY_LEFT_ALT);
  }
}

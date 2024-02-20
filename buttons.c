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


enum btn_press_t BTN_Processing( struct button_s *btn ){
  //Debounce
  if( btn->debounce != 0 ){
    btn->debounce--;
    return BTN_NO_PRESS;
  }
  //Processing
  btn->press = (bool)!digitalRead(btn->gpio);
  if( btn->prev_state != btn->press ){
    btn->prev_state = btn->press;
    if( btn->press ){
      LED_DebugBlink(false);
      btn->hold  = true;
      btn->timer = 300;
      return BTN_SHORT_PRESS;
    } else {
      LED_DebugBlink(true);
    }
    btn->debounce = BTN_DEBOUNCE_TIMEOUT;
  }else{
    if( btn->hold == true && btn->timer != 0 ){
      btn->timer--;
      if( btn->timer == 0){
        btn->hold = false;
        return BTN_LONG_PRESS;
      }
    }
  }
  return BTN_NO_PRESS;
}

void BTN_Main( void ){
  if( BTN_Processing( &btn4 ) == BTN_SHORT_PRESS ){
    //Sequence 'ä'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_8);
    Keyboard_release(KEY_LEFT_ALT);
    delay(100);
    Keyboard_releaseAll();
  }
  if( BTN_Processing( &btn3 ) == BTN_SHORT_PRESS ){
    //Sequence 'ö'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_4);
    Keyboard_click(KEYPAD_6);
    Keyboard_release(KEY_LEFT_ALT);
    delay(100);
    Keyboard_releaseAll();
  }
  if( BTN_Processing( &btn2 ) == BTN_SHORT_PRESS ){
    //Sequence 'ü'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_5);
    Keyboard_click(KEYPAD_2);
    Keyboard_release(KEY_LEFT_ALT);
    delay(100);
    Keyboard_releaseAll();
  }
  if( BTN_Processing( &btn1 ) == BTN_SHORT_PRESS ){
    //Sequence 'ß'
    Keyboard_press(KEY_LEFT_ALT);
    Keyboard_click(KEYPAD_0);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_2);
    Keyboard_click(KEYPAD_3);
    Keyboard_release(KEY_LEFT_ALT);
    delay(100);
    Keyboard_releaseAll();
  }
}

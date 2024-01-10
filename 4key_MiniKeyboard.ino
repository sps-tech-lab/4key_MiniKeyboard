/*
  ************************************************************************************
  * 4key MIni HID Keyboard
  * Date 2023 
  ************************************************************************************
*/
#ifndef USER_USB_RAM
#error "Require USB RAM, set: [Tools]->[USB Setting]->[USER CODEw/ 148b USB ram]"
#endif


//Includes
#include "USBHIDKeyboard.h"
#include <WS2812.h>


//Peripherals
#define BUTTON1_PIN 15
#define BUTTON2_PIN 16
#define BUTTON3_PIN 17
#define BUTTON4_PIN 11
#define LED1_PIN    30  //DEV BOARD
#define NEO_LED_PIN 34 

//Neo 8px line
#define NUM_LEDS    8
#define NUM_COLORS  3
#define NUM_BYTES   (NUM_LEDS*NUM_COLORS)

__xdata uint8_t led[NUM_BYTES];

bool buttonPressPrev = false;

void setup() {
  USBInit();
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);  //DEV BOARD

  //Initialize neopixels
  pinMode(NEO_LED_PIN, OUTPUT);
}


void loop() {
  //Button test
  bool buttonPress = !digitalRead(BUTTON1_PIN);
  if( buttonPressPrev != buttonPress ){
    buttonPressPrev = buttonPress;
    if( buttonPress ){
      Keyboard_press('H');
      digitalWrite(LED1_PIN,1);
    } else {
      Keyboard_releaseAll();
    }
    delay(50);  //debounce
  }

  //Neo test
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    set_pixel_for_GRB_LED(led, i, random(5), random(5), random(5));
    neopixel_show_P3_4(led, NUM_BYTES); 
  }
  delay(100); 
}

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

//Draft
struct rgb_s{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct rgb_s interpolateColors(const struct rgb_s *color1, const struct rgb_s *color2, int t, int maxSteps) {
    struct rgb_s result;
    
    result.red = color1->red + ((t * (color2->red - color1->red)) / maxSteps);
    result.green = color1->green + ((t * (color2->green - color1->green)) / maxSteps);
    result.blue = color1->blue + ((t * (color2->blue - color1->blue)) / maxSteps);

    return result;
}

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

void LED_Portal( void ){
  NEO_writeColor(0, 4, 20, 26 );
  NEO_writeColor(1, 35, 181, 232 );
  NEO_writeColor(2, 255, 50, 0 );
  NEO_writeColor(3, 26, 5, 0 );
  NEO_update();  
}

void LED_Cyberpunk( void ){

  if( rainbow_speed != 0 ){
    rainbow_speed--;
    return;
  }

  //Draft
  static bool flip = false;
  static uint8_t step;

  #define LED_FD_STEPS 100

  struct rgb_s cyan_start = {35, 181, 232};
  struct rgb_s cyan_endpt = {4, 20, 26};
  struct rgb_s cyan;
  struct rgb_s pink_start = {55, 0, 55};
  struct rgb_s pink_endpt = {255, 0, 255 };
  struct rgb_s pink;

  if( flip == true ){
    if( step > 0 ){
      step--;
    }else{
      flip = false;
    }
  }else{
    if( step < LED_FD_STEPS ){
      step++;
    }else{
      flip = true;
    }
  }
  cyan = interpolateColors(&cyan_start, &cyan_endpt, step, LED_FD_STEPS);
  pink = interpolateColors(&pink_start, &pink_endpt, step, LED_FD_STEPS);

  // Output the result
  NEO_writeColor(0, cyan.red, cyan.green, cyan.blue);
  NEO_writeColor(1, cyan.red, cyan.green, cyan.blue);
  NEO_writeColor(2, pink.red, pink.green, pink.blue);
  NEO_writeColor(3, pink.red, pink.green, pink.blue);

  // NEO_writeColor(0, 4, 20, 26 );
  // NEO_writeColor(1, 35, 181, 232 );
  // NEO_writeColor(2, 255, 0, 255 );
  // NEO_writeColor(3, 55, 0, 55 );
  NEO_update();  

  rainbow_speed = LED_RAINBOW_SPEED;
}



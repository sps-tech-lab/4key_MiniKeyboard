/*
  ************************************************************************************
  * Led custom indication patterns
  ************************************************************************************
*/
//Includes
#include "led.h"
#include "neo.h"
#include <Arduino.h>


//Patterns functions
void LED_NoLight( void );
void LED_Rainbow( void );
void LED_Portal( void );
void LED_Cyberpunk( void );

#define MAX_PATTERN_CELLS 4

//Patterns struct
struct{
  void (*ptr[MAX_PATTERN_CELLS])(void);
  uint8_t speed;
  uint8_t index;
}patterns = {
  .ptr[0] = LED_Rainbow,
  .ptr[1] = LED_Cyberpunk,
  .ptr[2] = LED_Portal,
  .ptr[3] = LED_NoLight,
  .speed  = LED_PATTERN_SPEED,
  .index  = 0,
};

//RGB color type
struct rgb_s{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

/**
  **************************************************************************************************
  * @brief      RGB color interpolation
  **************************************************************************************************
**/
struct rgb_s interpolateColors(const struct rgb_s *color1, const struct rgb_s *color2, int t, int maxSteps) {
    struct rgb_s result;
    
    result.red = color1->red + ((t * (color2->red - color1->red)) / maxSteps);
    result.green = color1->green + ((t * (color2->green - color1->green)) / maxSteps);
    result.blue = color1->blue + ((t * (color2->blue - color1->blue)) / maxSteps);

    return result;
}

/**
  **************************************************************************************************
  * @brief      CH552 dev. board LED (unnecessary for keybord PCB)
  **************************************************************************************************
**/
void LED_DebugBlink( bool state ){
#if DEBUG_LED
  if( state == true ){
    digitalWrite(DBG_LED_PIN, 1);
  }else{
    digitalWrite(DBG_LED_PIN, 0);
  }
#endif
}

/**
  **************************************************************************************************
  * @brief      Set current pattern
  **************************************************************************************************
**/
void LED_SetPattern( uint8_t index ){
  //Check for valid index and pattern cell
  if( index < MAX_PATTERN_CELLS ){ 
    if( patterns.ptr[index] != NULL ){
      patterns.index = index;
    }
  }
}

/**
  **************************************************************************************************
  * @brief      Main pattern periodic
  **************************************************************************************************
**/
void LED_Main( void ){
  patterns.ptr[patterns.index]();
}

/**
  **************************************************************************************************
  * @brief      To turn backlight off
  **************************************************************************************************
**/
void LED_NoLight( void ){
  //Dummy
}

/**
  **************************************************************************************************
  * @brief      Shifting HUE rainbow pattern 
  **************************************************************************************************
**/
void LED_Rainbow( void ){
  //Simple rainbow
  static uint8_t hue_1 = 0;
  static uint8_t hue_2 = 45;
  static uint8_t hue_3 = 90;
  static uint8_t hue_4 = 135;

  if( patterns.speed != 0 ){
    patterns.speed--;
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

  patterns.speed = LED_PATTERN_SPEED;
}

/**
  **************************************************************************************************
  * @brief      Portal.2 pulsing colors pattern
  **************************************************************************************************
**/
void LED_Portal( void ){

  if( patterns.speed != 0 ){
    patterns.speed--;
    return;
  }

  //Draft
  static bool flip = false;
  static uint8_t step;

  struct rgb_s color1_start = {35, 181, 232};
  struct rgb_s color1_endpt = {4, 20, 26};
  struct rgb_s color1;
  struct rgb_s color2_start = {26, 5, 0};
  struct rgb_s color2_endpt = {255, 50, 0 };
  struct rgb_s color2;

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
  color1 = interpolateColors(&color1_start, &color1_endpt, step, LED_FD_STEPS);
  color2 = interpolateColors(&color2_start, &color2_endpt, step, LED_FD_STEPS);

  // Output the result
  NEO_writeColor(0, color1.red, color1.green, color1.blue);
  NEO_writeColor(1, color1.red, color1.green, color1.blue);
  NEO_writeColor(2, color2.red, color2.green, color2.blue);
  NEO_writeColor(3, color2.red, color2.green, color2.blue);

  NEO_update();  

  patterns.speed = LED_PATTERN_SPEED;
}

/**
  **************************************************************************************************
  * @brief      Cyberpunk.2077 pulsing colors pattern
  **************************************************************************************************
**/
void LED_Cyberpunk( void ){

  if( patterns.speed != 0 ){
    patterns.speed--;
    return;
  }

  //Draft
  static bool flip = false;
  static uint8_t stage = 0;
  static uint8_t step;

  struct rgb_s cyan_start = {35, 181, 232};
  struct rgb_s cyan_endpt = {4, 20, 26};
  struct rgb_s cyan;
  struct rgb_s pink_start = {55, 0, 55};
  struct rgb_s pink_endpt = {255, 0, 255 };
  struct rgb_s pink;
  struct rgb_s black      = {1, 1, 1};


  // switch(stage){
  //   case 0: //Fade
  //     cyan = interpolateColors(&cyan_start, &cyan_endpt, step, LED_FD_STEPS);
  //     pink = interpolateColors(&pink_start, &pink_endpt, step, LED_FD_STEPS);
  //     if( step++ >= LED_FD_STEPS-1 ){
  //       stage++;
  //       step = 0;
  //     }
  //   break;
  //   case 1: //Hold
  //     if( step++ >= LED_FD_STEPS-1 ){
  //       stage++;
  //       step = 0;
  //     }
  //   break;
  //   case 2: //Transit
  //     cyan = interpolateColors(&cyan_endpt, &pink_start, step, LED_TR_STEPS);
  //     pink = interpolateColors(&pink_endpt, &cyan_start, step, LED_TR_STEPS);
  //     if( step++ >= LED_TR_STEPS-1 ){
  //       stage++;
  //       step = 0;
  //     }
  //   break;
  //   case 3: //Fade
  //     cyan = interpolateColors(&pink_start, &pink_endpt, step, LED_FD_STEPS);
  //     pink = interpolateColors(&cyan_start, &cyan_endpt, step, LED_FD_STEPS);
  //     if( step++ >= LED_FD_STEPS-1 ){
  //       stage++;
  //       step = 0;
  //     }
  //   break;
  //   case 4: //Hold
  //     if( step++ >= LED_FD_STEPS-1 ){
  //       stage++;
  //       step = 0;
  //     }
  //   break;
  //   case 5: //Transit
  //     cyan = interpolateColors(&pink_endpt, &cyan_start, step, LED_TR_STEPS);
  //     pink = interpolateColors(&cyan_endpt, &pink_start, step, LED_TR_STEPS);
  //     if( step++ >= LED_TR_STEPS-1 ){
  //       stage = 0;
  //       step = 0;
  //     }
  //   break;
  // }

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

  NEO_update();  
  patterns.speed = LED_PATTERN_SPEED;
}





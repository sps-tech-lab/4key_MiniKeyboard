/*
  ************************************************************************************
  * NeoPixel Functions for CH551, CH552 and CH554 based on <WS2812.h>
  ************************************************************************************
*/
//Includes
#include "neo.h"
#include <WS2812.h>


//Definitions
#define NEO_BYTES (3*NEO_COUNT)

//Variables
__xdata uint8_t NEO_buffer[NEO_BYTES];  // pixel buffer
__xdata uint8_t *ptr;                       // pixel buffer pointer


// Write Buffer to Pixels
void NEO_update(void) {
  neopixel_show_P3_4(NEO_buffer, NEO_BYTES); //TODO: add flexible pin selector
}


// Clear all Pixels
void NEO_clearAll(void) {
  uint8_t i;
  ptr = NEO_buffer;
  for( i = NEO_BYTES; i; i-- ){
    *ptr++ = 0;  
  } 
  NEO_update();
}

// Write Color to a Single Pixel in Buffer
void NEO_writeColor(uint8_t pixel, uint8_t r, uint8_t g, uint8_t b) {
  ptr = NEO_buffer + (3 * pixel);
  #if defined (NEO_GRB)
    *ptr++ = g; *ptr++ = r; *ptr = b;
  #elif defined (NEO_RGB)
    *ptr++ = r; *ptr++ = g; *ptr = b;
  #else
    #error Wrong or missing NeoPixel type definition!
  #endif
}

// Write Hue Value (0..191) and Brightness (0..2) to a Single Pixel in Buffer
void NEO_writeHue(uint8_t pixel, uint8_t hue, uint8_t bright) {
  uint8_t phase = hue >> 6;
  uint8_t step  = (hue & 63) << bright;
  uint8_t nstep = (63 << bright) - step;
  switch(phase) {
    case 0:   NEO_writeColor(pixel, nstep,  step,     0); break;
    case 1:   NEO_writeColor(pixel,     0, nstep,  step); break;
    case 2:   NEO_writeColor(pixel,  step,     0, nstep); break;
    default:  break;
  }
}

// Clear Single Pixel in Buffer
void NEO_clearPixel(uint8_t pixel) {
  NEO_writeColor(pixel, 0, 0, 0);
}

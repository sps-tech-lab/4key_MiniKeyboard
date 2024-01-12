/*
  ************************************************************************************
  * NeoPixel Functions for CH551, CH552 and CH554 based on <WS2812.h>
  ************************************************************************************
*/
#pragma once
#include <stdint.h>

//Config
#define NEO_COUNT 4	//Count
#define NEO_GRB		//Type

//Key colors (hue value: 0..191)
#define NEO_RED    0    // red
#define NEO_YEL    32   // yellow
#define NEO_GREEN  64   // green
#define NEO_CYAN   96   // cyan
#define NEO_BLUE   128  // blue
#define NEO_MAG    160  // magenta
#define NEO_WHITE  191  // white

//Key brightness 
#define NEO_BRIGHT_LOW 0
#define NEO_BRIGHT_MID 1
#define NEO_BRIGHT_HIG 2

//API
void NEO_clearAll(void);                                              // clear all pixels
void NEO_update(void);                                                // write buffer to pixels
void NEO_writeColor(uint8_t pixel, uint8_t r, uint8_t g, uint8_t b);  // write color to pixel in buffer
void NEO_writeHue(uint8_t pixel, uint8_t hue, uint8_t bright);        // hue (0..191), brightness (0..2)
void NEO_clearPixel(uint8_t pixel);                                   // clear one pixel in buffer

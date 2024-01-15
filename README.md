# 4key_MiniKeyboard

![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/GBenG/4key_MiniKeyboard?label=version)

## Description

Project of custom firmware for a 4-key macro keyboard from Aliexpress, utilizing the CH552 microcontroller to transform it into an AltCodes keyboard. 

![Ali_Keyboard](https://github.com/GBenG/4key_MiniKeyboard/raw/main/img/rd_1.jpg)

For now I havn't written any external key sequence configurator, so you just need to hardcode your own sequences and build own *.hex

## Build

Project simply use Arduino IDE

1. Install the Arduino IDE
2. Add CH552G Board:
   - Use this inctruction https://github.com/DeqingSun/ch55xduino
3. Open the project.
   - Set next config in Tools tab:
   - ![config](https://github.com/GBenG/4key_MiniKeyboard/raw/main/img/rd_2.jpg)
4. Compile the project
5. Set the keyboard in bootloader mode:
   - ![config](https://github.com/GBenG/4key_MiniKeyboard/raw/main/img/rd_3.jpg)
6. Flash the project


## Pinout

- BUTTON 1: P1.5
- BUTTON 2: P1.6
- BUTTON 3: P1.7
- BUTTON 4: P1.1
- NEO LEDS: P3.4


## Datasheet

- [CH552DS1_en.pdf](https://github.com/GBenG/4key_MiniKeyboard/raw/main/Datasheet/CH552DS1_en.pdf)


## Resources

- [ch552g_mini_keyboard](https://github.com/eccherda/ch552g_mini_keyboard/tree/master)
- [Ch55xduino: Small Devices Arduino for ch55x devices](https://github.com/DeqingSun/ch55xduino)
- [How to Program a Really Cheap Microcontroller](https://hackaday.com/2019/02/17/how-to-program-a-really-cheap-microcontroller/#more-345535)
- [RGB Macropad Custom Firmware](https://hackaday.io/project/189914-rgb-macropad-custom-firmware)
- [CH552G Macropad Plus](https://oshwlab.com/wagiminator/ch552g-macropad-plus)
- [ch554_sdcc on GitHub](https://github.com/Blinkinlabs/ch554_sdcc)
- [CH552G Product Page](https://www.esclabs.in/product/ch552g-8-bit-usb-device-microcontroller/)
- [LCSC Product Page](https://www.lcsc.com/product-detail/Microcontroller-Units-MCUs-MPUs-SOCs_WCH-Jiangsu-Qin-Heng-CH552G_C111292.html?utm_source=digipart&utm_medium=cpc&utm_campaign=CH552G)
- [CH552G Datasheet](http://www.wch-ic.com/downloads/file/309.html)
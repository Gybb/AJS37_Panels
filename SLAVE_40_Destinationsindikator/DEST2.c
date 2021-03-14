// DEST2.c
// Font type    : Numeric (10 characters)
// Font size    : 48x48 pixels
// Memory usage : 2884 bytes

#if defined(__AVR__)
    #include <avr/pgmspace.h>
    #define fontdatatype const uint8_t
#elif defined(__PIC32MX__)
    #define PROGMEM
    #define fontdatatype const unsigned char
#elif defined(__arm__)
    #define PROGMEM
    #define fontdatatype const unsigned char
#endif

fontdatatype DEST2[2884] PROGMEM={
0x30,0x30,0x30,0x0A,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xF0,0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,0x00,0x03,0xFF,0xFF,0x00,0x00,0x00,0x07,0xFF,0xFF,0x80,0x00,0x00,0x07,0xFC,0x3F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x80,0x00,0x00,0x0F,0xF8,0x1F,0x00,0x00,0x00,0x0F,0xF8,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x07,0xFE,0x00,0x00,0x00,0x00,0x07,0xFF,0x00,0x00,0x00,0x00,0x03,0xFF,0x00,0x00,0x00,0x00,0x03,0xFF,0x80,0x00,0x00,0x00,0x01,0xFF,0xC0,0x00,0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,0x00,0x7F,0xE0,0x00,0x00,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x03,0xFE,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x7F,0x00,0x00,0x00,0x07,0xF0,0xFE,0x00,0x00,0x00,0x07,0xFF,0xFE,0x00,0x00,0x00,0x07,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xF8,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 0
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x1F,0xF0,0x00,0x00,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x7F,0xF0,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x01,0xCF,0xF0,0x00,0x00,0x00,0x01,0x8F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 1
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,0x00,0x03,0xFF,0xFF,0x00,0x00,0x00,0x03,0xFC,0x7F,0x80,0x00,0x00,0x03,0xF8,0x3F,0x80,0x00,0x00,0x03,0xF8,0x3F,0x80,0x00,0x00,0x03,0xF8,0x3F,0x80,0x00,0x00,0x03,0xF8,0x3F,0x80,0x00,0x00,0x01,0xF8,0x3F,0x80,0x00,0x00,0x00,0xF0,0x3F,0x80,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x7F,0x80,0x00,0x00,0x00,0x00,0x7F,0x80,0x00,0x00,0x00,0x00,0xFF,0x80,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0xFF,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0x00,0x00,0x00,0x03,0xFE,0x00,0x00,0x00,0x00,0x03,0xFC,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x0F,0xF8,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x1F,0xF0,0x00,0x00,0x00,0x00,0x1F,0xE0,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0x00,0x00,0xFF,0x80,0x00,0x00,0x00,0x00,0xFF,0x80,0x00,0x00,0x00,0x01,0xFF,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0x00,0x00,0x00,0x03,0xFE,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x0F,0xF8,0x00,0x00,0x00,0x00,0x0F,0xF8,0x00,0x00,0x00,0x00,0x1F,0xF0,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFE,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x1F,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 2
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x07,0xFF,0xFE,0x00,0x00,0x00,0x07,0xF1,0xFE,0x00,0x00,0x00,0x07,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x07,0xE0,0xFE,0x00,0x00,0x00,0x03,0xC0,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x1F,0xFC,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x7F,0xF0,0x00,0x00,0x00,0x00,0x7F,0xF0,0x00,0x00,0x00,0x00,0x7F,0xF8,0x00,0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x1F,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x07,0xC0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x07,0xE0,0xFE,0x00,0x00,0x00,0x07,0xF1,0xFE,0x00,0x00,0x00,0x07,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xF8,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 3
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x03,0xFC,0x00,0x00,0x00,0x00,0x03,0xFC,0x00,0x00,0x00,0x00,0x03,0xFC,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x07,0xFC,0x00,0x00,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x1F,0xFC,0x00,0x00,0x00,0x00,0x1F,0xFC,0x00,0x00,0x00,0x00,0x1F,0xFC,0x00,0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0x7E,0xFC,0x00,0x00,0x00,0x00,0xFE,0xFC,0x00,0x00,0x00,0x00,0xFC,0xFC,0x00,0x00,0x00,0x01,0xFC,0xFC,0x00,0x00,0x00,0x01,0xFC,0xFC,0x00,0x00,0x00,0x01,0xF8,0xFC,0x00,0x00,0x00,0x03,0xF8,0xFC,0x00,0x00,0x00,0x03,0xF0,0xFC,0x00,0x00,0x00,0x03,0xF0,0xFC,0x00,0x00,0x00,0x07,0xF0,0xFC,0x00,0x00,0x00,0x07,0xE0,0xFC,0x00,0x00,0x00,0x0F,0xE0,0xFC,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 4
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xDF,0xE0,0x00,0x00,0x00,0x0F,0xFF,0xF8,0x00,0x00,0x00,0x0F,0xFF,0xFC,0x00,0x00,0x00,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xF8,0xFF,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x07,0x80,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x07,0xF0,0x7E,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 5
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0xFF,0xF8,0x00,0x00,0x00,0x01,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x07,0xFF,0xFF,0x00,0x00,0x00,0x07,0xF0,0x7F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x0F,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xDF,0xE0,0x00,0x00,0x00,0x0F,0xFF,0xF8,0x00,0x00,0x00,0x0F,0xFF,0xFC,0x00,0x00,0x00,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x0F,0xF8,0xFF,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x07,0xF0,0x7E,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 6
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x00,0x00,0x03,0xF8,0x00,0x00,0x00,0x00,0x03,0xF8,0x00,0x00,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x0F,0xE0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x1F,0xC0,0x00,0x00,0x00,0x00,0x1F,0xC0,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x00,0x00,0x03,0xF8,0x00,0x00,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 7
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0xFF,0xF8,0x00,0x00,0x00,0x01,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x07,0xFF,0xFF,0x00,0x00,0x00,0x07,0xF0,0x7F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x80,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x03,0xF0,0x7F,0x00,0x00,0x00,0x01,0xFF,0xFE,0x00,0x00,0x00,0x00,0xFF,0xFC,0x00,0x00,0x00,0x00,0x7F,0xF0,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x7F,0xF0,0x00,0x00,0x00,0x01,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x03,0xF0,0x7F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xC0,0x1F,0x80,0x00,0x00,0x0F,0xE0,0x3F,0x00,0x00,0x00,0x07,0xE0,0x3F,0x00,0x00,0x00,0x07,0xF0,0x7E,0x00,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 8
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x07,0xFF,0xFC,0x00,0x00,0x00,0x07,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xC0,0x7E,0x00,0x00,0x00,0x0F,0xC0,0x7F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0xC0,0x7F,0x00,0x00,0x00,0x1F,0xC0,0x7F,0x00,0x00,0x00,0x1F,0xF1,0xFF,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x00,0x00,0x00,0x07,0xFF,0xFF,0x00,0x00,0x00,0x03,0xFF,0xFF,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,0x00,0x00,0x7F,0xBF,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x0F,0x00,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0x80,0x3F,0x00,0x00,0x00,0x1F,0xC0,0x7F,0x00,0x00,0x00,0x0F,0xC0,0x7E,0x00,0x00,0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x07,0xFF,0xFC,0x00,0x00,0x00,0x07,0xFF,0xFC,0x00,0x00,0x00,0x03,0xFF,0xF8,0x00,0x00,0x00,0x01,0xFF,0xF0,0x00,0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // 9
};
//Datapanel Diplay
//AJS37

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 53
#define TXENABLE_PIN 2
#include "DcsBios.h"

U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI display1(U8G2_R0,/* cs=*/ 7, /* dc=*/ 6, /* reset=*/ 4);
//U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI display2(U8G2_R0,/* cs=*/ 5, /* dc=*/ 6, /* reset=*/ 8);
/*
  Fontname: AJS_DATA
  Copyright: outbaxx
  Glyphs: 12/26
  BBX Build Mode: 0
*/

void setup() {
  //start displays
  display1.begin();
  //display2.begin();
  //set contrast
  display1.setContrast(50);
  //display2.setContrast(50);
  //font for displays
  display1.setFont(u8g2_font_courR18_tn); 
  //display2.setFont(AJSDATA);
//draw 37 
  //display1.drawStr(-10,45," 37 ");
  //display1.sendBuffer();
  //display2.drawStr(-10,55," 37");
  //display2.sendBuffer();
DcsBios::setup();

}

//
//*************Update Display*************

void onAltimeterBaro1HpaChange(unsigned int newValue) {
  display1.clearBuffer();
  display1.drawStr(-10,25,newValue-1);  
  display1.drawStr(-10,45,newValue);
  display1.drawStr(-10,65,newValue+1);
  display1.sendBuffer();
}
DcsBios::IntegerBuffer altimeterBaro1HpaBuffer(0x4636, 0xffff, 0, onAltimeterBaro1HpaChange);

void loop(){
  DcsBios::loop();
 }

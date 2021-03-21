//Datapanel Diplay
//AJS37

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 22
#define TXENABLE_PIN 2
#include "DcsBios.h"
U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI display1(U8G2_R0,/* cs=*/ 7, /* dc=*/ 6, /* reset=*/ 4);
U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI display2(U8G2_R0,/* cs=*/ 5, /* dc=*/ 6, /* reset=*/ 8);
/*
  Fontname: AJS_DATA38
  Copyright: outbaxx
  Glyphs: 12/26
  BBX Build Mode: 0
*/
const uint8_t AJSDATA[531] U8G2_FONT_SECTION("AJSDATA") = 
  "\14\0\4\4\5\6\6\7\7\42%\0\0$\0%\377\0\0\0\0\1\366 \6\0\0\313r-\15\220"
  "\200\243\362p\361\340\201\10\27\0\60&S|\203\362J\330\352\321\233\7BL\31)W\302\334J\375\377"
  "\227\353L\224+b\312\310\3\61\217^\65L\5\0\61\27K\234\205r#f\350\14\222\24\17>\30Q"
  "\254\376\377\177\67\2\0\62\64S|\203\362J\330\352\321\233\7BL\31)W\302\340\302\342\245-\66m"
  "\330\360a\253\15\33>l\265a\253\15\233.\375 \310\203\21\17F<\30\362 \4\0\63\64S|\205"
  "\362J\330\352\321\33SF\312\25)W\302\340\302\342U\27/]\62\323\264\311\215\227\7P\274<\200\205"
  "\273\63Q\256\210)#\17\304<z\325\60\25\0\64\62S|\203r\65m\370Z\234f\251\303\22\5K"
  "\224+R\256H\261\62\305\312\24#T\252P)R\205J\25z \342\301\3\24\17\306\26\257\357\1\14"
  "\2\65\70S|\205\362x\20\344\301\210\7#\36\214x \244x\375\342\330\243\7a\36\10y \344\224"
  "\11s%\314\225\7P\274\370\302\335\231(W\304\224\221\7b\36\275j\230\12\0\66\67S|\203\362J"
  "\330\352\321\233\7BL\31)W\302\334\302\235\27\61\366\350A\230\7B\36\10\71e\302\134\11s%J"
  "\352\313u&\312\25\61e\344\201\230G\257\32\246\2\67,R\204\201r\370\3\326\25\227.\134\272p\351"
  "\302\245\13\227.\134\272p\351\302\245\13\227.\134\272p\351\302\245\13\227.M\36\200x\0\70\70S|"
  "\203\362J\330\352\321\33SF\312\25)W\242\244.K\224+R\256L\251R\355\26\256k\365\250T\231"
  "rE\312\225(\251\227%\312\25)W\304\224\231G\257\32\246\2\71\67S|\203\362J\330\352\321\233\7"
  "BL\31)W\302\334J}Y\242\234\211r&L\35y \344\201\230\7\201\236\31)\276pw&\312"
  "\25\61e\344\201\230G\257\32\246\2\0\0\0\4\377\377\0";


void setup() {
  //start displays
  display1.begin();
  display2.begin();
  //set contrast
  display1.setContrast(50);
  display2.setContrast(50);
  //font for displays
  display1.setFont(AJSDATA); 
  display2.setFont(AJSDATA);
//draw 37 
  display1.drawStr(-10,45," 37 ");
  display1.sendBuffer();
  //display2.drawStr(-10,55," 37");
  //display2.sendBuffer();
DcsBios::setup();
}

void onDatadisplay1to3Change(char* newValue) {
  display1.clearBuffer();  
  display1.drawStr(-10,45,newValue);
  display1.sendBuffer();
}
DcsBios::StringBuffer<3> datadisplay1to3Buffer(0x46be, onDatadisplay1to3Change);

void onDatadisplay4to6Change(char* newValue) {
  display2.clearBuffer();  
  display2.drawStr(-10,45,newValue);
  display2.sendBuffer();
}
DcsBios::StringBuffer<3> datadisplay4to6Buffer(0x46c2, onDatadisplay4to6Change);


void loop(){
  DcsBios::loop();
}

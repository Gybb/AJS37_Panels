#include <Arduino.h>
#include <UTFT.h>
#include <SPI.h>
//#include <avr/pgmspace.h>
//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 40
#define TXENABLE_PIN 2
#include "DcsBios.h"

const char* Bxred = "5";
const char* Ured = "7";

UTFT myGLCD(ST7735S_4L_80160,11,13,10,8,9);  //ST7735 0.96" 80x160(RGB)IPS

extern uint8_t DEST1[];
extern uint8_t DEST2[];

void setup()
{
  myGLCD.InitLCD(LANDSCAPE);
  //myGLCD.lcdOff();
  //myGLCD.setBrightness(1);
  //myGLCD.setContrast(1);
  myGLCD.clrScr();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(245, 195, 80);
  myGLCD.setFont(DEST2);
  myGLCD.print("37", 40, 18);
  myGLCD.clrScr();

  DcsBios::setup();
}
//Left_Indicator
void onajs37DestIndicatorDataVChange(char* newValue) {
  myGLCD.setFont(DEST1);
    
    if (strcmp(newValue, "7") == 0){
      //om värdet är 7 så visa röd färg
     myGLCD.setColor(150, 0, 0);
     myGLCD.print(newValue, 12, 18);
    }
    else{
      myGLCD.setColor(245, 195, 80);
      myGLCD.print(newValue, 12, 18);
    }
}
DcsBios::StringBuffer<1> ajs37DestIndicatorDataVBuffer(0x46c6, onajs37DestIndicatorDataVChange);

//Right_Indicator
void onajs37DestIndicatorDataHChange(char* newValue) {
    myGLCD.setFont(DEST2);
    myGLCD.setColor(245, 195, 80);
    myGLCD.print(newValue, 95, 18);
}
DcsBios::StringBuffer<1> ajs37DestIndicatorDataHBuffer(0x46c8, onajs37DestIndicatorDataHChange);


void loop()
{
   DcsBios::loop();

}

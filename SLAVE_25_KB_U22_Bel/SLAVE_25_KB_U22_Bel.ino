//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 25
#define TXENABLE_PIN 2

#include "DcsBios.h"

DcsBios::AnalogMultiPos u22FkSelector("U22_FK_SELECTOR", A7, 4, (1023/4));

DcsBios::AnalogMultiPos u22OeSelector("U22_OE_SELECTOR", A6, 4, (1023/4));
//---------------------------------------------------------------


DcsBios::Switch3Pos kbModeSelectorRrff("KB_MODE_SELECTOR_RRFF", 11, 10);

DcsBios::Switch2Pos kbModeSelector04("KB_MODE_SELECTOR_04", 9);

DcsBios::Switch3Pos kbApp27Mmode("KB_APP27_MMODE", 8, 7);

DcsBios::AnalogMultiPos kbModeSelectorA3("KB_MODE_SELECTOR_A3", A5, 4, (1023/4));
// PIN 5 for PWM LED
//int PanelLight_pin = 5;

DcsBios::Switch2Pos antiCollisionLights("ANTI_COLLISION_LIGHTS", 3);

DcsBios::Switch3Pos navigationLights("NAVIGATION_LIGHTS", A0, 4);

DcsBios::Switch2Pos formationLights("FORMATION_LIGHTS", A1);

DcsBios::Switch2Pos positionLights("POSITION_LIGHTS", A2);

//form/pos styrka
//DcsBios::Switch3Pos positionLightBright("POSITION_LIGHT_BRIGHT", A0, 4);
/*
//----------------Panelbelysning--------------------------------------------------------
bool PanelLed_Power;
unsigned int PanelLed_Value;

//----*Check Main Power Switch
void onMainElectricPowerChange(unsigned int newValue) {
      PanelLed_Power = newValue; 
}
DcsBios::IntegerBuffer mainElectricPowerBuffer(0x4606, 0x0010, 4, onMainElectricPowerChange);

//----*Read Panel Lights Value
void onPanelLightsChange(unsigned int newValue) {
 PanelLed_Value = newValue;
}
DcsBios::IntegerBuffer panelLightsBuffer(0x4678, 0xffff, 0, onPanelLightsChange);

//----*Set LED Panel Lights
void setPanelLights(unsigned int PanelLed_Value){
   if(!PanelLed_Power){
    PanelLed_Value = 0;
  }
  else {
      PanelLed_Value = map(PanelLed_Value, 0, 65535, 0, 200);
  }
     analogWrite(PanelLight_pin, PanelLed_Value); 
}
//---------------Panelbelysning Slut-------------------------------------------
*/
void setup() {
  
  DcsBios::setup();
  //pinMode(PanelLight_pin, OUTPUT);
}


void loop() {
  DcsBios::loop();
  //setPanelLights(PanelLed_Value);
   }

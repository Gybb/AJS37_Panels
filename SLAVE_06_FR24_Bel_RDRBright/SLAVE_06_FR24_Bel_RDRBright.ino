//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 6
#define TXENABLE_PIN 2

#include "DcsBios.h"

DcsBios::RotaryEncoder floodLights("FLOOD_LIGHTS", "-1024", "+1024", 11, 12);
//DcsBios::RotaryEncoder instrumentLights("INSTRUMENT_LIGHTS", "-3200", "+3200", PIN_A, PIN_B);
DcsBios::RotaryEncoder panelLights("PANEL_LIGHTS", "-1024", "+1024", 10, 9);
// PIN 5 for PWM LED
//int PanelLight_pin = 5;

DcsBios::AnalogMultiPos fr24ModeSelector("FR24_MODE_SELECTOR", A7, 5, (1023/5));

DcsBios::Switch2Pos fr24GroundCom("FR24_GROUND_COM", 8);

DcsBios::Switch2Pos fr24Sm("FR24_SM", 7);

DcsBios::Switch3Pos fr24MikBand("FR24_MIK_BAND", 5, 6);

//DcsBios::PotentiometerEWMA<5, 128, 5> radarBright("RADAR_BRIGHT", PIN);
DcsBios::RotaryEncoder fr24Vol("FR24_VOL", "-1024", "+1024", 3, A0);


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

#define DCSBIOS_RS485_SLAVE 21
#define TXENABLE_PIN 2

#include "DcsBios.h"

//*********************** DATAPANEL ********************************
DcsBios::Switch2Pos datapanelKey1("DATAPANEL_KEY_1", 12);

DcsBios::Switch2Pos datapanelKey2("DATAPANEL_KEY_2", 11);

DcsBios::Switch2Pos datapanelKey3("DATAPANEL_KEY_3", 10);

DcsBios::Switch2Pos datapanelKey4("DATAPANEL_KEY_4", 9);

DcsBios::Switch2Pos datapanelKey5("DATAPANEL_KEY_5", 8);

DcsBios::Switch2Pos datapanelKey6("DATAPANEL_KEY_6", 7);

DcsBios::Switch2Pos datapanelKey7("DATAPANEL_KEY_7", 6);

// PIN 5 for PWM LED
int PanelLight_pin = 5;

DcsBios::Switch2Pos datapanelKey8("DATAPANEL_KEY_8", 4);

DcsBios::Switch2Pos datapanelKey9("DATAPANEL_KEY_9", 3);

DcsBios::Switch2Pos ck37RensaClear("CK37_RENSA_CLEAR", A0);

DcsBios::Switch2Pos datapanelKey0("DATAPANEL_KEY_0", A1);

DcsBios::Switch2Pos dataInOut("DATA_IN_OUT", A2);

//DcsBios::Switch2Pos rensaButtonCover("RENSA_BUTTON_COVER", A3);

DcsBios::AnalogMultiPos datapanelSelector("DATAPANEL_SELECTOR", A7, 6, (1023/6));
//*********************** DATAPANEL SLUT ********************************

//----------Check switch states --------------
unsigned int g_iInitIntervalCounter = 0;
unsigned int g_iForcePollCycles = 10;
void PollAllControls()
{
    dataInOut.pollInputCurrent();
    datapanelSelector.pollInputCurrent();
  }

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
void setup() {
  
  DcsBios::setup();
  pinMode(PanelLight_pin, OUTPUT);
}


void loop() {
  DcsBios::loop();
  setPanelLights(PanelLed_Value);
    if ( g_iForcePollCycles > 0 )
    { 
        //repeat poll for this many cycles
        if ( ++g_iInitIntervalCounter == 21 ) 
        {  PollAllControls();     //main loop 1->65535->0 then polls
           g_iForcePollCycles--;
        }

    }

}

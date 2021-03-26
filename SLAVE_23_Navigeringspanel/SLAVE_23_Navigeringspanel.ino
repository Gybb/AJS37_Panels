//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 23
#define TXENABLE_PIN 2

#include "DcsBios.h"

DcsBios::Switch2Pos dmeSelector("DME_SELECTOR", 13);

DcsBios::Switch2Pos radarAltimeterPower("RADAR_ALTIMETER_POWER", 12);

DcsBios::Switch2Pos navSelectBtnB1("NAV_SELECT_BTN_B1", 11);

DcsBios::Switch2Pos navSelectBtnB2("NAV_SELECT_BTN_B2", 10);

DcsBios::Switch2Pos navSelectBtnB3("NAV_SELECT_BTN_B3", 9);

DcsBios::Switch2Pos navSelectBtnB4("NAV_SELECT_BTN_B4", 8);

DcsBios::Switch2Pos navSelectBtnB5("NAV_SELECT_BTN_B5", 7);

DcsBios::Switch2Pos navSelectBtnB6("NAV_SELECT_BTN_B6", 6);

// PIN 5 for PWM LED
int PanelLight_pin = 5;
int PanelLed_Value;

DcsBios::Switch2Pos navSelectBtnB7("NAV_SELECT_BTN_B7", 4);

DcsBios::Switch2Pos navSelectBtnB8("NAV_SELECT_BTN_B8", 3);

DcsBios::Switch2Pos navSelectBtnB9("NAV_SELECT_BTN_B9", A0);

DcsBios::Switch2Pos navSelectBtnBx("NAV_SELECT_BTN_BX", A1);

DcsBios::Switch2Pos navSelectBtnLMal("NAV_SELECT_BTN_L_MAL", A2);

DcsBios::Switch2Pos navSelectBtnLs("NAV_SELECT_BTN_LS", A3);

DcsBios::AnalogMultiPos tilsChannelSelect("TILS_CHANNEL_SELECT", A7, 11, (1023/11));
//*******************NAVPANEL SLUT******************************
//----------Check switch states polls-----------------
unsigned int g_iInitIntervalCounter = 0;
unsigned int g_iForcePollCycles = 10;

void setup() {
  
  DcsBios::setup();
 //  pinMode(PanelLight_pin, OUTPUT);
}

void onMainElectricPowerChange(unsigned int newValue) {
    if (newValue==0){
      PanelLed_Value = 0; }
}
DcsBios::IntegerBuffer mainElectricPowerBuffer(0x4606, 0x0010, 4, onMainElectricPowerChange);
  
void onPanelLightsChange(unsigned int newValue) {
      PanelLed_Value = map(newValue, 0, 65535, 0, 200);
     analogWrite(PanelLight_pin, PanelLed_Value);
}
DcsBios::IntegerBuffer panelLightsBuffer(0x4678, 0xffff, 0, onPanelLightsChange);



void loop() {
  DcsBios::loop();
         if ( g_iForcePollCycles > 0 )
    { 
        //repeat poll for this many cycles
        if ( ++g_iInitIntervalCounter == 0 ) 
        {  PollAllControls();     //main loop 1->65535->0 then polls
           g_iForcePollCycles--;
        }

    }

}

void PollAllControls()
{
    dmeSelector.pollInputCurrent();
    radarAltimeterPower.pollInputCurrent();
    tilsChannelSelect.pollInputCurrent();
  }

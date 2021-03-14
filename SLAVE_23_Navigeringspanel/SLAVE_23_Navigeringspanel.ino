//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 23
#define TXENABLE_PIN 2

#include "DcsBios.h"

DcsBios::Switch2Pos dmeSelector("DME_SELECTOR", 12);

DcsBios::Switch2Pos radarAltimeterPower("RADAR_ALTIMETER_POWER", 11);

DcsBios::Switch2Pos navSelectBtnB1("NAV_SELECT_BTN_B1", 10);

DcsBios::Switch2Pos navSelectBtnB2("NAV_SELECT_BTN_B2", 9);

DcsBios::Switch2Pos navSelectBtnB3("NAV_SELECT_BTN_B3", 8);

DcsBios::Switch2Pos navSelectBtnB4("NAV_SELECT_BTN_B4", 7);

DcsBios::Switch2Pos navSelectBtnB5("NAV_SELECT_BTN_B5", 6);

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


void setup() {
  
  DcsBios::setup();
 //  pinMode(PanelLight_pin, OUTPUT);
}

void onMainElectricPowerChange(unsigned int newValue) {
    if (newValue==0){
      PanelLed_Value = 0; }
}
DcsBios::IntegerBuffer mainElectricPowerBuffer(0x4650, 0x0008, 3, onMainElectricPowerChange);
  
void onPanelLightsChange(unsigned int newValue) {
      PanelLed_Value = map(newValue, 0, 65535, 0, 200);
     analogWrite(PanelLight_pin, PanelLed_Value);
}
DcsBios::IntegerBuffer panelLightsBuffer(0x464c, 0xffff, 0, onPanelLightsChange);



void loop() {
  DcsBios::loop();
  }

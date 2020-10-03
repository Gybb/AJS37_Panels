
#define DCSBIOS_RS485_SLAVE 21
#define TXENABLE_PIN 2

#include "DcsBios.h"

DcsBios::Switch2Pos datapanelKey1("DATAPANEL_KEY_1", 12);

DcsBios::Switch2Pos datapanelKey2("DATAPANEL_KEY_2", 11);

DcsBios::Switch2Pos datapanelKey3("DATAPANEL_KEY_3", 10);

DcsBios::Switch2Pos datapanelKey4("DATAPANEL_KEY_4", 9);

DcsBios::Switch2Pos datapanelKey5("DATAPANEL_KEY_5", 8);

DcsBios::Switch2Pos datapanelKey6("DATAPANEL_KEY_6", 7);

DcsBios::Switch2Pos datapanelKey7("DATAPANEL_KEY_7", 6);

// PIN 5 for PWM LED
int PanelLight_pin = 5;
int PanelLed_Value;

DcsBios::Switch2Pos datapanelKey8("DATAPANEL_KEY_8", 4);

DcsBios::Switch2Pos datapanelKey9("DATAPANEL_KEY_9", 3);

DcsBios::Switch2Pos ck37RensaClear("CK37_RENSA_CLEAR", A0);

DcsBios::Switch2Pos datapanelKey0("DATAPANEL_KEY_0", A1);

DcsBios::Switch2Pos dataInOut("DATA_IN_OUT", A2);

//DcsBios::Switch2Pos rensaButtonCover("RENSA_BUTTON_COVER", A3);

DcsBios::AnalogMultiPos datapanelSelector("DATAPANEL_SELECTOR", A7, 6, (1023/6));


void setup() {
  
  DcsBios::setup();
 //  pinMode(PanelLight_pin, OUTPUT);
}

void onMainElectricPowerChange(unsigned int newValue) {
    if (newValue==0){
      PanelLed_Value = 0; }
}
DcsBios::IntegerBuffer mainElectricPowerBuffer(0x460e, 0x4000, 14, onMainElectricPowerChange);
  
void onPanelLightsChange(unsigned int newValue) {
      PanelLed_Value = map(newValue, 0, 65535, 0, 200);
     analogWrite(PanelLight_pin, PanelLed_Value);
}
DcsBios::IntegerBuffer panelLightsBuffer(0x460a, 0xffff, 0, onPanelLightsChange);



void loop() {
  DcsBios::loop();
  }

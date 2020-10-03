#define DCSBIOS_RS485_SLAVE 4
#define TXENABLE_PIN 2
#include "DcsBios.h"

//*******************  RADARPANEL  ****************************/
//*******************  PANELKORT   ****************************/
/*LAND/SJÖ på pin 8*/
DcsBios::Switch2Pos dopplerLandSeaMode("DOPPLER_LAND_SEA_MODE", 8);
//Need more coding, LAND/SJÖ does not work as a toggle switch in DCS
/*RR TILL på pin 7*/
DcsBios::Switch2Pos radarIgnitionCoils("RADAR_IGNITION_COILS", 7);
/*LIN/LOG på pin 6*/
DcsBios::Switch2Pos radarGain("RADAR_GAIN", 6);
// PIN 5 for PWM LED
int PanelLight_pin = 5;
int PanelLed_Value;
/*PULS NORMAL/KORT på pin 4*/
DcsBios::Switch2Pos radarPulseNormalShort("RADAR_PULSE_NORMAL_SHORT", 4);
/*PASSIV SPAN TILL/FRÅN på pin 3*/
DcsBios::Switch2Pos radarRecceOnOff("RADAR_RECCE_ON_OFF", 3);
/*SKEDESVÄLJARE på pin A7*/
DcsBios::AnalogMultiPos masterModeSelect("MASTER_MODE_SELECT", A7, 6, (1023/6));
/*AS vridomkopplare på pin A6*/
DcsBios::AnalogMultiPos antiJamMode("ANTI_JAM_MODE", A6, 7, (1023/7));

//*******************  SLUT RADARPANEL  ***********************/

void setup() {
  DcsBios::setup();
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

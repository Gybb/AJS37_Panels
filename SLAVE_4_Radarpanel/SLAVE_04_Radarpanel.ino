#define DCSBIOS_RS485_SLAVE 4
#define TXENABLE_PIN 2
#include "DcsBios.h"

//*******************  RADARPANEL  ****************************/
//*******************  PANELKORT   ****************************/
/*LAND/SJÖ på pin 8*/
DcsBios::Switch2Pos dopplerLandSeaMode("DOPPLER_LAND_SEA_MODE", 8);
//Need more coding, LAND/SJÖ does not work as a toggle switch in DCS
/*RR TILL på pin 7*(Tvekamt om denna fungerar alls)/
DcsBios::Switch2Pos radarMaintenanceTest("RADAR_MAINTENANCE_TEST", 7);
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
//---------- Check switch states --------------
unsigned int g_iInitIntervalCounter = 0;
unsigned int g_iForcePollCycles = 10;
//
void PollAllControls()
{
    //dopplerLandSeaMode.pollInputCurrent(); Doesnt matter
    radarGain.pollInputCurrent();
    radarPulseNormalShort.pollInputCurrent();
    radarRecceOnOff.pollInputCurrent();
    masterModeSelect.pollInputCurrent();
    antiJamMode.pollInputCurrent();
 }

//---------------- Panelbelysning ------------------------------------------------------
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
        if ( ++g_iInitIntervalCounter == 4 ) 
        {  PollAllControls();     //main loop 1->65535->0 then polls
           g_iForcePollCycles--;
        }

    }

}

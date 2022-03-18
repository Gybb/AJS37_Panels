/*Definierad som SLAVE 3
 */
#define DCSBIOS_RS485_SLAVE 3
#define TXENABLE_PIN 2
#include "DcsBios.h"

const int StartSolenoid_pin = 5;
int Sol_Value;
int RPM_Less40;
bool power_is_on;
bool LTkran_is_on;

  

//*******************  STARTPANEL  ****************************/
//******************* 9 PINNAR ********************************/
/* LT-KRAN LAMPA på pin 13*/
DcsBios::LED ltKranLamp(0x4606, 0x0800, 13);
/*HUVUDSTRÖM på pin 12*/
DcsBios::Switch2Pos mainElectricPower("MAIN_ELECTRIC_POWER", 12);
/*LT-KRAN på pin 11*/
DcsBios::Switch2Pos lowPresFuelValve("LOW_PRES_FUEL_VALVE", 11);
/*TÄNDSYSTEM på pin 10 */
DcsBios::Switch2Pos ignitionSystem("IGNITION_SYSTEM", 10, true);
/*GENERATOR på pin 9*/
DcsBios::Switch2Pos generator("GENERATOR", 9);
/*START is on pin 8*/
DcsBios::Switch2Pos startSystem("START_SYSTEM", 8);
/* ÅTERSTART på pin 7*/
DcsBios::Switch2Pos restart("RESTART", 7);
/* NÖDSKJUT HUV på 6*/
DcsBios::Switch2Pos canopyJettison("CANOPY_JETTISON", 6);
/* RENFLYGN på A7*/
//DcsBios::Potentiometer autoYawTrim("AUTO_YAW_TRIM", A7);
DcsBios::Potentiometer panelLights("PANEL_LIGHTS", A7);
//RENFLYGN DOES NOT WORK, DONT KNOW WHY, STRANGE SYNTAX IN CLICKABLE.LUA
//*******************  SLUT STARTPANEL  ***********************/

unsigned int g_iInitIntervalCounter = 0;
unsigned int g_iForcePollCycles = 5;

void setup() {
  DcsBios::setup(); 

// Solenoid for start switch, makes sure it only work when it should
pinMode(StartSolenoid_pin, OUTPUT);
}
void updateSolenoid(unsigned int Solenoid_pin, unsigned int Cpt_value){
      if (power_is_on && LTkran_is_on || RPM_Less40 > 30000){
         Sol_Value = map(Cpt_value, 0, 1, 0, 255);
      }
   else {
      Sol_Value = 0;
}
     analogWrite(StartSolenoid_pin, Sol_Value);
}

void onMainElectricPowerChange(unsigned int newValue) {
    power_is_on = newValue;
}
DcsBios::IntegerBuffer mainElectricPowerBuffer(0x4606, 0x0010, 4, onMainElectricPowerChange);

void onLowPresFuelValveChange(unsigned int newValue) {
   LTkran_is_on = newValue;
}
DcsBios::IntegerBuffer lowPresFuelValveBuffer(0x4606, 0x0020, 5, onLowPresFuelValveChange);

void onEngineRpm100Change(unsigned int RPM100Value) {
    RPM_Less40 = RPM100Value;
}
DcsBios::IntegerBuffer engineRpm100Buffer(0x4652, 0xffff, 0, onEngineRpm100Change);

void onStartSolChange(unsigned int Cpt_Value) {
   updateSolenoid(StartSolenoid_pin, Cpt_Value);
}
DcsBios::IntegerBuffer startSolBuffer(0x4606, 0x0100, 8, onStartSolChange);



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
    mainElectricPower.pollInputCurrent();
    lowPresFuelValve.pollInputCurrent();
    ignitionSystem.pollInputCurrent();
    generator.pollInputCurrent();
    startSystem.pollInputCurrent();
    //restart.pollInputCurrent(); BUTTON
    //canopyJettison.pollInputCurrent(); BUTTON
}

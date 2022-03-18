//#define DCSBIOS_IRQ_SERIAL
#define DCSBIOS_RS485_SLAVE 30
#define TXENABLE_PIN 2
#include "DcsBios.h"

const int altLAMP = 9;
const int attLAMP = 7;
const int spakLAMP = 4; 
//
//****************** Instrumentpanel:Lampor,brytare***************

DcsBios::LED hVarnVaLampa(0x4602, 0x0080, 13);
DcsBios::Switch2Pos masterCautionReset("MASTER_CAUTION_RESET", 12);
DcsBios::LED hVarnHoLampa(0x4602, 0x0100, 11);

DcsBios::ActionButton altitudeHold("ALTITUDE_HOLD","TOGGLE", 10);
//DcsBios::LED altitudeHold(0x4614, 0x0020, 9);
DcsBios::ActionButton attitudeHold("ATTITUDE_HOLD","TOGGLE", 8);
//DcsBios::LED attitudeHold(0x4614, 0x0010, 7);
DcsBios::ActionButton spak("SPAK", "TOGGLE",6);
//DcsBios::LED spak(0x4614, 0x0008, 4);

DcsBios::LED ebkSteg1Lampa(0x4602, 0x0010, 3);
DcsBios::LED ebkSteg2Lampa(0x4602, 0x0020, A0);
DcsBios::LED ebkSteg3Lampa(0x4602, 0x0040, A1);

DcsBios::LED reverseringLampa(0x466c, 0x0800, A2);
DcsBios::Switch2Pos reversal("REVERSAL", A3,true);

//DcsBios::Switch2Pos cbCiSi("CB_CI_SI", 5);
//DcsBios::Switch2Pos slavSi("SLAV_SI", PIN);
//DcsBios::LED afk15Lampa(0x466c, 0x8000, PIN);
//DcsBios::LED afkLampa(0x466c, 0x4000, PIN);
//DcsBios::LED transRevAvdr(0x466e, 0x1000, PIN);
//DcsBios::LED falldLastLampa(0x466e, 0x0800, PIN);
//DcsBios::LED hojdVarning(0x466c, 0x0400, PIN);
void onAltitudeHoldChange(unsigned int newValue) {
    digitalWrite(altLAMP, newValue);
}
DcsBios::IntegerBuffer altitudeHoldBuffer(0x4614, 0x0020, 5, onAltitudeHoldChange);

void onAttitudeHoldChange(unsigned int newValue) {
    digitalWrite(attLAMP, newValue);
 }
DcsBios::IntegerBuffer attitudeHoldBuffer(0x4614, 0x0010, 4, onAttitudeHoldChange);

void onSpakChange(unsigned int newValue) {
    digitalWrite(spakLAMP, newValue);
}
DcsBios::IntegerBuffer spakBuffer(0x4614, 0x0008, 3, onSpakChange);

void setup() {
  DcsBios::setup();
  pinMode (altLAMP, OUTPUT);
  pinMode (attLAMP, OUTPUT);
  pinMode (spakLAMP, OUTPUT);
}

void loop() {
  DcsBios::loop();
}

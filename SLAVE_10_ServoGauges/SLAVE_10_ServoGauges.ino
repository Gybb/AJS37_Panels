

#define DCSBIOS_RS485_SLAVE 10
#define TXENABLE_PIN 2

//#define DCSBIOS_IRQ_SERIAL
#define USE_PCA9685_SERVO_EXPANDER
#include "ServoEasing.hpp"
#include "DcsBios.h"
const int TrimServo_PIN = 9;
const int AOAServo_PIN = 8;
const int DistIndServo_PIN = 7;
const int DistIntFlagServo_PIN = 6;
const int RPMServo_PIN = 5;
const int EPRServo_PIN = 4;
int pos = 0; 
//Servo flag;  // servo object
ServoEasing TrimServo(PCA9685_DEFAULT_ADDRESS, &Wire);
ServoEasing AOAServo(PCA9685_DEFAULT_ADDRESS, &Wire);
ServoEasing DistIndServo(PCA9685_DEFAULT_ADDRESS, &Wire);
ServoEasing DistIntFlagServo(PCA9685_DEFAULT_ADDRESS, &Wire);
ServoEasing RPMServo(PCA9685_DEFAULT_ADDRESS, &Wire);
ServoEasing EPRServo(PCA9685_DEFAULT_ADDRESS, &Wire);
void setup() {
  DcsBios::setup();
  Wire.begin();
 // flag.attach(9); //servo on pin 9
  //pinMode(13, OUTPUT);
  TrimServo.attach(TrimServo_PIN, 60);
  AOAServo.attach(AOAServo_PIN, 170);
  DistIndServo.attach(DistIndServo_PIN, 90);
  DistIntFlagServo.attach(DistIntFlagServo_PIN, 45);
  RPMServo.attach(RPMServo_PIN, 90);
  EPRServo.attach(EPRServo_PIN, 90);
}
//-------------          TRIM_PIN_9     -------------------------------------------
void onPitchTrimChange(unsigned int newValue) {
   pos = map(newValue, 0, 65535, 92, 45);
  TrimServo.startEaseTo(pos, 360);
}
DcsBios::IntegerBuffer pitchTrimBuffer(0x46cc, 0xffff, 0, onPitchTrimChange);

//-------------          AOA_PIN_8     -------------------------------------------
void onAoaNeedleChange(unsigned int newValue) {
    pos = map(newValue, 0, 57500, 180, 0);
  AOAServo.startEaseTo(pos, 360);
}
DcsBios::IntegerBuffer aoaNeedleBuffer(0x463e, 0xffff, 0, onAoaNeedleChange);

//-------------          DistInd_PIN_7    -------------------------------------------
void onDistanceIndicatorChange(unsigned int newValue) {
 pos = map(newValue, 0, 26214, 180, 0);
  DistIndServo.startEaseTo(pos, 360);
}
DcsBios::IntegerBuffer distanceIndicatorBuffer(0x4658, 0xffff, 0, onDistanceIndicatorChange);

//-------------          DistIndFlag_PIN_6    -------------------------------------------
void onDistanceIndicatorKmMilChange(unsigned int newValue) {
     if(newValue == 0){
      pos = 0;
      }
      else{
      pos = 45;
     }
  DistIntFlagServo.startEaseTo(pos, 360);
}
DcsBios::IntegerBuffer distanceIndicatorKmMilBuffer(0x465a, 0xffff, 0, onDistanceIndicatorKmMilChange);

//-------------          RPMServo_PIN_5    -------------------------------------------
void onEngineRpm100Change(unsigned int newValue) {
   pos = map(newValue, 0, 65535, 180, 0);
  RPMServo.startEaseTo(pos, 360);
}
DcsBios::IntegerBuffer engineRpm100Buffer(0x4652, 0xffff, 0, onEngineRpm100Change);

//-------------          EPRServo_PIN_4    -------------------------------------------
void onEprNeedleChange(unsigned int newValue) {
      if(newValue >= 57500){
      pos = 57500;
      }
      else{
      pos = map(newValue, 0, 57500, 200, 0);  
     }
EPRServo.startEaseTo(pos, 360);
}
DcsBios::IntegerBuffer eprNeedleBuffer(0x4656, 0xffff, 0, onEprNeedleChange);

void loop() {

  DcsBios::loop();
}

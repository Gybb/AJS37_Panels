#include <Servo.h>
#define DCSBIOS_RS485_SLAVE 60
#define TXENABLE_PIN 2
#include "DcsBios.h"

//DcsBios::ServoOutput distanceIndicator(0x4666, 9, 740, 2400);
Servo distInd;  // servo object
int pos;


void setup() {
  DcsBios::setup();
  distInd.attach(9); //servo on pin 9

}
void onDistanceIndicatorChange(unsigned int newValue) {
 pos = map(newValue, 0, 26214, 2000, 1000);
  distInd.writeMicroseconds(pos);
}
DDcsBios::IntegerBuffer distanceIndicatorBuffer(0x4658, 0xffff, 0, onDistanceIndicatorChange);

void loop() {
  DcsBios::loop();
}

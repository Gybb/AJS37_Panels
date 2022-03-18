
//#define DCSBIOS_RS485_SLAVE 51

//#define TXENABLE_PIN 2
#define DCSBIOS_IRQ_SERIAL
#include <AccelStepper.h>
#include "DcsBios.h"

bool power_is_on;

struct StepperConfig {
  unsigned int maxSteps;
  unsigned int acceleration;
  unsigned int maxSpeed;
};


class Vid29Stepper : public DcsBios::Int16Buffer {
  private:
    AccelStepper& stepper;
    StepperConfig& stepperConfig;
    unsigned int (*map_function)(unsigned int);
    unsigned char initState;
  public:
    Vid29Stepper(unsigned int address, AccelStepper& stepper, StepperConfig& stepperConfig, unsigned int (*map_function)(unsigned int))
    : Int16Buffer(address), stepper(stepper), stepperConfig(stepperConfig), map_function(map_function), initState(0) {
    }

    virtual void loop() {
      if (initState == 0) { // not initialized yet
        stepper.setMaxSpeed(stepperConfig.maxSpeed);
        stepper.setAcceleration(stepperConfig.acceleration);
        //stepper.runToNewPosition(-((long)stepperConfig.maxSteps/2));
        stepper.runToNewPosition(stepperConfig.maxSteps);
        stepper.moveTo(-((long)stepperConfig.maxSteps));
        stepper.setMaxSpeed(stepperConfig.maxSpeed);
        stepper.setAcceleration(stepperConfig.acceleration);
        initState = 1;
      }
      if (initState == 1) { // zeroing
        stepper.run();
        if (stepper.currentPosition() <= -((long)stepperConfig.maxSteps)) {
          stepper.setCurrentPosition(0);
          initState = 2;
          //stepper.moveTo(stepperConfig.maxSteps);
          stepper.runToNewPosition(stepperConfig.maxSteps);
          stepper.runToNewPosition(0);
        }
        
      }
      if (initState == 2) { // running normally
        if (hasUpdatedData()) {
          unsigned int newPosition = map_function(getData());
          newPosition = constrain(newPosition, 0, stepperConfig.maxSteps);
          stepper.moveTo(newPosition);
         }
         stepper.run();
      }
     
    }
};

/* modify below this line */

/* define stepper parameters
   multiple Vid29Stepper instances can share the same StepperConfig object 
struct StepperConfig RPMConfig = {
  4100,  // maxSteps
  2000, // maxSpeed
  500 // acceleration
  };
*/
/* CraigS - testing with 11 going to step (middle on easy drier) and 10 doing to direction (right on easy driver)
// CraigS so in the code going on the basis that the first named number is step and the second is direction
// define AccelStepper instance
AccelStepper stepper(AccelStepper::DRIVER, 11, 10);
// define Vid29Stepper class that uses the AccelStepper instance defined in the line above
//           +-- arbitrary name
//           |   +-- Address of stepper data (from control reference)
//           |   |       +-- name of AccelStepper instance
//           v   v       v    v-- StepperConfig struct instance
Vid29Stepper engineRpm100(0x462a, stepper, stepperConfig, [](unsigned int newValue) -> unsigned int {
  // this function needs to map newValue to the correct number of steps
  return map(newValue, 0, 65535, 0, stepperConfig.maxSteps);
}); */

//
//Bränslemätare
struct StepperConfig FuelLevelConfig = {
  5760,  // maxSteps (1310,7)
  3000, // maxSpeed
  1500 // acceleration
  };
AccelStepper FuelLevel(AccelStepper::DRIVER, 8, 7);
Vid29Stepper airspeed(0x465c, FuelLevel, FuelLevelConfig, [](unsigned int newValue) -> unsigned int {
  return map(newValue, 0, 65535, 0, 5260);
}); 
//BränsleBehov
struct StepperConfig FuelLevelNeedConfig = {
  5760,  // maxSteps (1310,7)
  3000, // maxSpeed
  1500 // acceleration
  };
AccelStepper FuelLevelNeed(AccelStepper::DRIVER, 4, 6);
Vid29Stepper airspeed(0x465e, FuelLevelNeed, FuelLevelNeedConfig, [](unsigned int newValue) -> unsigned int {
  return map(newValue, 0, 65535, 0, 5260);
}); 
void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}

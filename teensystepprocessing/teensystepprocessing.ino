#include "io.h"
#include "com.h"
#include <Metro.h>  // Include the Metro library

Metro newTest = Metro(100);        // Configure test flag to 100ms interval

void setup() {
  initIo();
  initCom();
  initSteppers();
  printSerialCommandsAvailable(); 
}

void loop() {
  //readSerial();
  if(recvData()) {
    for(uint8_t i = 0; i < 6; i++) {
       setGoal(i, getPosition(i));
    }    
    moveMotors();
    //moveMotorsAsync();
  }
  if (newTest.check()) {
    toggleLed();
    displayAllCountSerial1();
  }
}

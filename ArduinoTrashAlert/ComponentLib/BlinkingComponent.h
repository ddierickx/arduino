/*
  BlinkingComponent.h - Simple blinking component
*/
#ifndef BlinkingComponent_h
#define BlinkingComponent_h

#include "ArduinoComponent.h"
#include "WProgram.h"

class BlinkingComponent : public ArduinoComponent
{
   public:
     BlinkingComponent(String name, unsigned long interval, int ledpin);
     void setup();
     void loop();
   protected:
     int pin;
     boolean on;
};

#endif

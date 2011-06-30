/*
  BlinkingComponent.h - Simple blinking component
*/
#ifndef TimeSyncComponent_h
#define TimeSyncComponent_h

#include "ArduinoComponent.h"
#include "WProgram.h"

class TimeSyncComponent : public ArduinoComponent
{
   public:
     TimeSyncComponent(String name);
     void setup();
     void loop();
     void processSyncMessage();
};

#endif

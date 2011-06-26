/*
  ArduinoApp.h - Library for Arduino Application Development
*/
#ifndef ArduinoApp_h
#define ArduinoApp_h

#include "WProgram.h"
#include "ArduinoComponent.h"
#include <iterator>
#include <vector>


class ArduinoApp
{
  public: 
    ArduinoApp();
    void registerComponent(ArduinoComponent* component);
    std::vector<ArduinoComponent*> getComponents();
    void setup();
    void loop();
  private:
    std::vector<ArduinoComponent*> components;
};

#endif

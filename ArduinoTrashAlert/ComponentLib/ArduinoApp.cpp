#include "WProgram.h"
#include "ArduinoApp.h"
#include <iterator>
#include <vector>

ArduinoApp::ArduinoApp()
{
}

void ArduinoApp::setup()
{        
  components.reserve(5);

  for (int i=0; i < components.size(); i++)
  {
    ArduinoComponent* component = components[i];
    component->setup();
    Serial.println(component->getName() + " - setup completed!");
  }
}

void ArduinoApp::loop()
{
  unsigned long currentmillis = millis();
  
    for (int i=0; i < components.size(); i++)
    {
      ArduinoComponent* component = components[i];

       if ( (currentmillis - component->getLastExec() >= component->getInterval()) || (component->getLastExec() == 0-1) )
       {
         component->loop();

         component->setLastExec(currentmillis);
       }
    }
}

void ArduinoApp::registerComponent(ArduinoComponent* component)
{
  components.push_back(component);
}

std::vector<ArduinoComponent*> ArduinoApp::getComponents()
{
    return components;
}

#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <QRandomGenerator>
#include "event.h"

class EventGenerator
{
public:
    EventGenerator();
    void Generate(std::vector<Event> &Events,QTime currentTime);
private:
   //public sex only

};

#endif // EVENTGENERATOR_H

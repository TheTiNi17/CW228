#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <time.h>
#include <stdio.h>
#include "event.h"

class EventGenerator
{
public:
    EventGenerator();
private:
    int EventsAmount = 20;
    enum Types
    {
        Sex = 1,
        Beggit,
        Anal,
        Ebal,
        Sosal
    };
};

#endif // EVENTGENERATOR_H

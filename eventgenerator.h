#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <QRandomGenerator>
#include <time.h>
#include <stdio.h>
#include "event.h"
#include "fileparser.h"

class EventGenerator
{
public:
    EventGenerator();
    void Generate(std::vector<Event>,QTime currentTime);
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

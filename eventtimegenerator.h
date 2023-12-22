#ifndef EVENTTIMEGENERATOR_H
#define EVENTTIMEGENERATOR_H

#include <QRandomGenerator>
#include "event.h"

class EventTimeGenerator
{
public:
    EventTimeGenerator();
    void Generate(std::vector<Event> &Events,QTime CurrentTime);
};

#endif // EVENTTIMEGENERATOR_H

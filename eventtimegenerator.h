#ifndef EVENTTIMEGENERATOR_H
#define EVENTTIMEGENERATOR_H

#include <QRandomGenerator>

#include "event.h"

class EventTimeGenerator
{
public:
    EventTimeGenerator();
    void GenerateRandom(std::vector<Event> &Events,QTime CurrentTime);
    void GenerateRandomNormal(std::vector<Event> &Events,QTime CurrentTime);

private:
    std::random_device rd;
};

#endif // EVENTTIMEGENERATOR_H

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <QTime>

class Event
{
public:
    Event();
    void Print();
    Event(std::string NewName, std::string NewType, int NewInter);
    std::string GetName();
    std::string GetType();
private:
    std::string TypeName = "default type";
    int Inter = 0;
    std::string Name = "default name";
};

#endif // EVENT_H
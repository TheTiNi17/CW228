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
    int GetStart();
    int GetEnd();
    void SetStart(int newStart);
    void SetEnd(int newEnd);
private:
    std::string TypeName = "default type";
    int Inter = 0;
    std::string Name = "default name";
    int Start;
    int End;

};

#endif // EVENT_H

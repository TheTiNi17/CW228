#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <QTime>

class Event
{
public:
    Event();
    std::string ReturnPrint();
    void Print();
    Event(std::string NewName, std::string NewType, int NewInter);
    std::string GetName();
    std::string GetType();
    int GetInterval();
    QTime GetStart();
    QTime GetEnd();
    void SetStart(QTime newStart);
    void SetEnd(QTime newEnd);
private:
    std::string TypeName = "default type";
    int Inter = 0;
    std::string Name = "default name";
    QTime Start;
    QTime End;
};

#endif // EVENT_H

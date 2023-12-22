#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <QTime>
#include <random>

class Event
{
public:
    Event();
    Event(std::string NewName, std::string NewType, int NewInter);
    ~Event();

    void Print();
    std::string ReturnPrint();
    std::string ReturnPrintWithTime();

    void SetStart(QTime newStart);
    void SetEnd(QTime newEnd);

    std::string GetName();
    std::string GetType();
    int GetInterval();
    QTime GetStart();
    QTime GetEnd();

private:
    std::string TypeName;
    int Interval;
    std::string Name;
    QTime Start;
    QTime End;
};

#endif // EVENT_H

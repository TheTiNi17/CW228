#include "event.h"

Event::Event()
{
    Name = "default name";
    TypeName = "default type";
    Interval = 0;
    QTime Start = QTime(0, 0, 0, 0);
    QTime End = QTime(0, 0, 0, 0);
}

Event::~Event()
{
    Name.clear();
    TypeName.clear();
    Interval = 0;
}

Event::Event(std::string NewName, std::string NewType, int NewInter)
{
    TypeName = NewType;
    Name = NewName;
    Interval = NewInter;
    QTime Start = QTime(0, 0, 0, 0);
    QTime End = QTime(0, 0, 0, 0);
}

void Event::Print()
{
    std::cout << "Название: " << Name <<" Тип: " << TypeName << " Интервал: " << Interval;
}

std::string Event::ReturnPrint()
{
    std::string Str = "Название: " + Name + " Тип: " + TypeName + " Интервал: " + std::to_string(Interval);
    return Str;
}

std::string Event::ReturnPrintWithTime()
{
    std::string Str = "Название: " + Name + " Тип: " + TypeName + " Интервал: " + std::to_string(Interval) + " Начало: " + Start.toString().toStdString() + " Конец: " + End.toString().toStdString();
    return Str;
}

void Event::SetStart(QTime newStart)
{
    Start = newStart;
}

void Event::SetEnd(QTime newEnd)
{
    End =newEnd;
}


std::string Event::GetName()
{
    return Name;
}

std::string Event::GetType()
{
    return TypeName;
}

int Event::GetInterval()
{
    return Interval;
}

QTime Event::GetStart()
{
    return Start;
}

QTime Event::GetEnd()
{
    return End;
}

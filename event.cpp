#include "event.h"

Event::Event()
{
    //Hittler ZIGA ZAGA
}

Event::Event(std::string NewName, std::string NewType, int NewInter)
{
    TypeName = NewType;
    Name = NewName;
    Inter = NewInter;
}

void Event::Print()
{
    std::cout << "Название: " << Name <<" Тип: " << TypeName << " Интервал: " << Inter;
}

std::string Event::ReturnPrint()
{
    std::string Str = "Название: " + Name + " Тип: " + TypeName + " Интервал: " + std::to_string(Inter);
    return Str;
}

std::string Event::GetType()
{
    return TypeName;
}

std::string Event::GetName()
{
    return Name;
}

int Event::GetStart()
{
    return Start;
}

int Event::GetEnd()
{
    return End;
}

void Event::SetStart(int newStart)
{
    Start = newStart;
}

void Event::SetEnd(int newEnd)
{
    End = newEnd;
}

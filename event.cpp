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
    std::cout << "\nName: " << Name <<" Type: " << TypeName << " int: " << Inter;
}

std::string Event::GetName()
{
    return Name;
}

std::string Event::GetType()
{
    return TypeName;
}

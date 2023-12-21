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

std::string Event::ReturnPrint()
{
    std::string Str = "\nName: " + Name + " Type: " + TypeName + " int: " + std::to_string(Inter);
    return Str;
}

std::string Event::GetName()
{
    return Name;
}

std::string Event::GetType()
{
    return TypeName;
}

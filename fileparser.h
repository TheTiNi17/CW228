#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>

#include "event.h"

class FileParser
{
private:
    std::vector<Event> Events;
    int Error = 0;
    //std::string FileName = "hui.txt";
public:
    std::vector<Event> FileContent(std::string FileName);
    FileParser();
    ~FileParser();
    int Check();
};

#endif // FILEPARSER_H

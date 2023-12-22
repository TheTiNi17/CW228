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
    void EventsShaffle(std::vector<Event> &Events);
    std::vector<Event> Events;
    int SizeError = 0; // 0 - 20 событий (нет ошибки)
                       // 1 - файл не отрывается
                       // 2 - кол-во событий от 5 до 30 (предупреждение)
                       // 3 - кол-во событий меньше 5 или больше 30

    int EventSettingsError = 0; // 1 - более чем 3 слова в описании события
                                // 2 - 3ий параметр (интервал) не целое число
                                // 3 - 3ий параметр больше 5 или меньше 3 (допустимо [3; 5])

public:
    FileParser();
    ~FileParser();

    std::vector<Event> GetFileContent(std::string FileName);

    int CheckSize();
    int CheckEvents();
};

#endif // FILEPARSER_H

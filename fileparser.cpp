#include "fileparser.h"

FileParser::FileParser()
{
    //std::string Result = FileContent(FileName);
}

FileParser::~FileParser()
{
    Events.clear();
}


std::vector<Event> FileParser::FileContent(std::string FileName)
{
    Events.clear(); // массив обнуляется
    Error = 0; //ошибка обнуляется
    //получение содержимого файла
    std::ifstream file(FileName);
    if (!file.is_open())
    {
        //std::cout << "Ошибка: файл " << FileName << " не найден\n";
        Error = 1;
        return Events;
    }

    std::stringstream StringStream;
    StringStream << file.rdbuf();
    std::string Content = StringStream.str();

    file.close();

    std::vector<std::string> EventsStrings;

    //std::cout << "File content: " << Content << "\n\n";

    std::string delimiter = "; "; // Символ-разделитель
    size_t pos = 0; // Переменная для хранения позиции разделителя
    std::string token; // Переменная для хранения отдельных подстрок

    while ((pos = Content.find(delimiter)) != std::string::npos)
    { // Пока находим разделитель
        token = Content.substr(0, pos); // Получаем подстроку до разделителя

        //std::cout << token << std::endl; // Выводим подстроку
        EventsStrings.push_back(token);

        Content.erase(0, pos + delimiter.length()); // Удаляем обработанную часть строки
    }

    //std::cout << Content << std::endl; // Выводим оставшуюся часть строки
    EventsStrings.push_back(Content);

    //OUTPUT 1
    /*
    std::cout << "\nFirst:\n";
    for (int i = 0; i < EventsStrings.size(); i++)
    {
        std::cout << EventsStrings.at(i) << "\n";
    }
    */

    std::vector<std::string> tmp;
    std::vector<std::vector<std::string>> tmptmp;

    for (int i = 0; i < EventsStrings.size(); i++)
    {
        delimiter = ", "; // Символ-разделитель
        pos = 0; // Переменная для хранения позиции разделителя
        token = ""; // Переменная для хранения отдельных подстрок
        Content = EventsStrings.at(i);

        while ((pos = Content.find(delimiter)) != std::string::npos)
        { // Пока находим разделитель
            token = Content.substr(0, pos); // Получаем подстроку до разделителя

            tmp.push_back(token); // Сохраняем подстроку

            Content.erase(0, pos + delimiter.length()); // Удаляем обработанную часть строки
        }

        tmp.push_back(Content);// Сохраняем оставшуюся часть строки

        //check size == 3

        if (tmp.size() != 3)
        {
            Error = 2;
            //return Events;
        }
        else
        {
            tmptmp.push_back(tmp);
        }
        tmp.clear();
    }

    //OUTPUT 2
    /*
    std::cout << "\nSecond:\n";
    for (int i = 0; i < tmptmp.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tmptmp.at(i).at(j) << "\n";
        }
    }*/

    int Number = 0;

    //std::cout << tmptmp.size();
    for (int i = 0; i < tmptmp.size(); i++)
    {
        try
        {
            Number = std::stoi(tmptmp.at(i).at(2)); // Пробуем преобразовать строку в int
            Event newevent = Event(tmptmp.at(i).at(0), tmptmp.at(i).at(1), Number);
            Events.push_back(newevent);
        } catch (...)
        {
            Error = 3; // Если возникло исключение, Error
            ///
        }
    }

    //std::cout << "Amount of Events: " Events.size();
    //THIRD
    /*
    for (int i = 0; i < Events.size(); i++)
    {
        Events.at(i).Print();
    }
    */

    if ((Events.size() < 31) && (Events.size() > 4) && (Events.size() != 20)) // от 30 до 5 ивентов в зоне доступности
    {
        Error = 4;
    }

    else
    {
        Error = 5; // хуйня
    }

    tmp.clear();
    tmptmp.clear();

    return Events;
}

int FileParser::Check()
{
    return Error;
}

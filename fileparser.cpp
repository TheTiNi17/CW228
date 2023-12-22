#include "fileparser.h"

FileParser::FileParser(){}

FileParser::~FileParser()
{
    Events.clear();
    SizeError = 0;
    EventSettingsError = 0;
}

std::vector<Event> FileParser::GetFileContent(std::string FileName)
{
    Events.clear(); // Массив обнуляется
    EventSettingsError = 0; // Ошибка параметров ивента обнуляется
    SizeError = 0; // Ошибка обнуляется

    // Получение содержимого файла
    std::ifstream file(FileName);
    if (!file.is_open())
    {
        SizeError = 1; // Ошибка: файл FileName не найден";
        return Events;
    }
    //

    // Преобразование файла в строку
    std::stringstream StringStream;
    StringStream << file.rdbuf();
    std::string Content = StringStream.str();
    file.close();
    //

    // Дробление строки по ивентам
    std::vector<std::string> EventsStrings; // Содержит строки ивентов
    std::string delimiter = "; "; // Символ-разделитель
    size_t pos = 0; // Переменная для хранения позиции разделителя
    std::string token; // Переменная для хранения отдельных подстрок

    while ((pos = Content.find(delimiter)) != std::string::npos) // пока находим разделитель
    {
        token = Content.substr(0, pos); // Получаем подстроку до разделителя
        EventsStrings.push_back(token); // Сохраняем подстроку
        Content.erase(0, pos + delimiter.length()); // Удаляем обработанную часть строки
    }
    EventsStrings.push_back(Content); // Сохраняем оставшуюся часть строки
    //

    // Получение из строк параметр для Event
    std::vector<std::string> tmp;
    std::vector<std::vector<std::string>> tmptmp;

    for (int i = 0; i < EventsStrings.size(); i++)
    {
        delimiter = ", "; // Символ-разделитель
        pos = 0; // Переменная для хранения позиции разделителя
        token = ""; // Переменная для хранения отдельных подстрок
        Content = EventsStrings.at(i);

        while ((pos = Content.find(delimiter)) != std::string::npos)
        {
            token = Content.substr(0, pos);
            tmp.push_back(token);
            Content.erase(0, pos + delimiter.length());
        }
        tmp.push_back(Content);
        //

        // Проверка на правильное кол-вл параметров для ивента
        if (tmp.size() != 3) // Некорректные события игнорируются
        {
            EventSettingsError = 1;
        }
        else
        {
            tmptmp.push_back(tmp);
        }
        tmp.clear();
        //
    }
    //

    // Проверка на корректность параметра интервала
    int Number = 0;

    for (int i = 0; i < tmptmp.size(); i++)
    {
        try
        {
            Number = std::stoi(tmptmp.at(i).at(2)); // Пробуем преобразовать строку в int

            if ((Number > 5) || (Number < 3)) // Недопустимое значение для интервала
            {
                EventSettingsError = 3;
            }
            else
            {
                Event newevent = Event(tmptmp.at(i).at(0), tmptmp.at(i).at(1), Number);
                Events.push_back(newevent);
            }
        } catch (...)
        {
            EventSettingsError = 2; // Если возникло исключение, 3 параметр не целое число
        }
    }
    //

    // Проверка на кол-во ивентов
    if ((Events.size() < 31) && (Events.size() > 4) && (Events.size() != 20)) // от 30 до 5 ивентов в зоне доступности
    {
        SizeError = 2;
    }
    else // Слишком много или мало ивентов
    {
        SizeError = 3;
    }
    //

    // Сброс переменных
    tmp.clear();
    tmptmp.clear();
    //
    return Events;
}

int FileParser::CheckSize()
{
    return SizeError;
}

int FileParser::CheckEvents()
{
    return EventSettingsError;
}

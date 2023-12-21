#include "eventgenerator.h"

EventGenerator::EventGenerator()
{}

void EventGenerator::Generate(std::vector<Event> &Events, QTime currentTime)
{

    QRandomGenerator *generator = QRandomGenerator::global();

    for (int i = 0; i < Events.size(); i++)
    {
        int Begin = generator->bounded(1, 30); // Генерируем первое число от 1 до 30
        int diff = Events.at(i).GetInterval();

        Events.at(i).SetStart(currentTime.addSecs(Begin));
        Events.at(i).SetEnd(currentTime.addSecs(Begin + diff));
    }








    /* QList<QPair<QTime, QTime>> pairs;
    QRandomGenerator *generator = QRandomGenerator::global();

    for (int i = 0; i < EventsAmount; ++i)
    {
        int Start = generator->bounded(1, 30); // Генерируем первое число от 1 до 30
        int diff = Events.at(i).GetInterval();
        int End = Start+diff;

        QTime newStart = QTime().addSecs(Start);
        QTime newEnd = QTime().addSecs(End);
        pairs.append(qMakePair(newStart, newEnd)); // Добавляем пару в список
    }

    for (int i = 0; i<EventsAmount; i++)
    {
        Events[i].SetStart(pairs[i].first);
        Events[i].SetEnd(pairs[i].second);
    }
*/
}

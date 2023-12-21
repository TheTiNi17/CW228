#include "eventgenerator.h"

EventGenerator::EventGenerator()
{

}

void EventGenerator::Generate(std::vector<Event> Events)
{
    QList<QPair<int, int>> pairs;
    QRandomGenerator *generator = QRandomGenerator::global();

    for (int i = 0; i < EventsAmount; ++i) {
        int Start = generator->bounded(1, 15); // Генерируем первое число от 1 до 15
        int diff = generator->bounded(1, 6); // Генерируем разницу от 1 до 5
        int End = qBound(1, Start + diff, 15); // Генерируем второе число с учётом ограничения от 1 до 15
        pairs.append(qMakePair(Start, End)); // Добавляем пару в список
    }
    for (int i = 0; i<EventsAmount; i++)
    {
        std::cout << pairs[i].first << ", " << pairs[i].second << '\n';
    }
    /*
    for (int i = 0; i<EventsAmount; i++)
    {
        Events[i].SetStart(pairs[i].first);
        Events[i].End(pairs[i].second);
    }
    */
}

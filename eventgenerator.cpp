#include "eventgenerator.h"

EventGenerator::EventGenerator(){}

void EventGenerator::Generate(std::vector<Event> &Events, QTime CurrentTime)
{
    QRandomGenerator *generator = QRandomGenerator::global();
    for (int i = 0; i < Events.size(); i++)
    {
        int RandomStart = generator->bounded(1, 30); // Генерируем случайное число от 1 до 30 временные рамки генерации от (T1 = 4 до T2 = 35) секунд

        Events.at(i).SetStart(CurrentTime.addSecs(RandomStart)); // Интервал это значение от 3 до 5
        Events.at(i).SetEnd(CurrentTime.addSecs(RandomStart + Events.at(i).GetInterval()));
    }
}

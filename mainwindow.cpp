#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr = new QTimer(this); // Создание объекта класса QTimer и передаем адресс переменной
    tmr->setInterval(1000); // Задаем интервал таймера
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime())); // Подключаем сигнал таймера к нашему слоту

    tmr->start(); // Запускаем таймер
    ui->TrackingButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
}

void MainWindow::PrintEvents()
{
    ui->AllEventsOutput->setText("");
    for (int i = 0; i < Events.size(); i++)
    {
        ui->AllEventsOutput->append(QString::fromStdString("№ " + std::to_string(i + 1) + ": " + Events.at(i).ReturnPrint()));
    }
}

void MainWindow::PrintEventsWithTime()
{
    ui->AllEventsOutput->setText("");
    for (int i = 0; i < Events.size(); i++)
    {
        ui->AllEventsOutput->append(QString::fromStdString("№ " + std::to_string(i + 1) + ": " + Events.at(i).ReturnPrintWithTime()));
    }
}

int MainWindow::EventActualityChecker(int NumberOfEvent)
{
    QTime now = QTime::currentTime();
    if (Events.at(NumberOfEvent).GetStart() > now)
    {
        if (Events.at(NumberOfEvent).GetEnd() < now)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

void MainWindow::updateTime()
{
    ui->label->setText(QTime::currentTime().toString());
}

void MainWindow::on_TrackingButton_clicked()
{
    /*EventGenerator g;

    g.Generate(Events, QTime::currentTime());
    QTime EndOfExecution = QTime::currentTime().addSecs(36);

    PrintEventsWithTime();

    while (EndOfExecution > QTime::currentTime())
    {
        updateTime(); // часы на экране пользователя
        //ui->ActiveEventsOutput->setText("");

        for (int i = 0; i < Events.size(); i++)
        {
            if (EventActualityChecker(i))
            {
                ui->ActiveEventsOutput->append(QString::fromStdString(Events.at(i).ReturnPrint()));
            }
        }
    }*/
}

void MainWindow::on_CheckFileButton_clicked()
{
    ui->AllEventsOutput->setText("");
    ui->TrackingButton->setEnabled(false);
    Events.clear();

    Events = fileparser.GetFileContent(ui->CheckFileLine->text().toStdString());

    //int EventChecker = fileparser.CheckEvents();
    int SizeChecker = fileparser.CheckSize();

    switch(SizeChecker)
    {
        case 1: // файл не алё
            ErrorMsgBox.setIcon(QMessageBox::Critical);
            ErrorMsgBox.setWindowTitle("Critical!");
            ErrorMsgBox.setText("Не удалось открыть файл!");
            ErrorMsgBox.exec();
            break;
        case 2: // ивентов от 5 до 30, но не 20 НЕКРИТИЧ
            ErrorMsgBox.setIcon(QMessageBox::Warning);
            ErrorMsgBox.setWindowTitle("Warnig!");
            ErrorMsgBox.setText("Неправильный размер!");
            ErrorMsgBox.exec();
            ui->TrackingButton->setEnabled(true);
            break;
        case 3: // ивентов меньше 5 или больше 30 КРИТИЧ
            ErrorMsgBox.setIcon(QMessageBox::Critical);
            ErrorMsgBox.setWindowTitle("Critical!");
            ErrorMsgBox.setText("Неправильный размер!");
            ErrorMsgBox.exec();
            break;
        case 0:
            ui->TrackingButton->setEnabled(true);
            break;
    }

    if (ui->TrackingButton->isEnabled())
    {
        PrintEvents();
    }
}


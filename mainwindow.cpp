#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer = new QTimer(this); // Создание объекта класса QTimer и передаем адресс переменной
    Timer->setInterval(1000); // Задаем интервал таймера
    connect(Timer, SIGNAL(timeout()), this, SLOT(updateTime())); // Подключаем сигнал таймера к нашему слоту
    Timer->start(); // Запускаем таймер

    Generator = new EventTimeGenerator();
    Fileparser = new FileParser();

    ui->TrackingButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Timer;
    delete Generator;
    delete Fileparser;
    Events.clear();
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
    TmpTime = QTime::currentTime();
    if (Events.at(NumberOfEvent).GetStart() <= TmpTime)
    {
        if (Events.at(NumberOfEvent).GetEnd() >= TmpTime)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

void MainWindow::updateTime()
{
    ui->label->setText(QString::fromStdString(" " + QTime::currentTime().toString().toStdString() + " "));
}

void MainWindow::UpdateActiveEvents()
{
    ui->ActiveEventsOutput->setText("");
    for (int i = 0; i < Events.size(); i++)
    {
        if (EventActualityChecker(i))
        {
            ui->ActiveEventsOutput->append(QString::fromStdString("№ " + std::to_string(i + 1) + ": " + Events.at(i).ReturnPrintWithTime()));
        }
    }

    if (EndOfExecution <= QTime::currentTime())
    {
        disconnect(Timer, SIGNAL(timeout()), this, SLOT(UpdateActiveEvents())); // Подключаем сигнал таймера к нашему слоту
    }
}

void MainWindow::on_TrackingButton_clicked()
{
    Generator->Generate(Events, QTime::currentTime());
    EndOfExecution = QTime::currentTime().addSecs(37);

    PrintEventsWithTime();

    connect(Timer, SIGNAL(timeout()), this, SLOT(UpdateActiveEvents())); // Подключаем сигнал таймера к слоту печати активных ивентов
}

void MainWindow::on_CheckFileButton_clicked()
{
    ui->AllEventsOutput->setText("");
    ui->TrackingButton->setEnabled(false);
    Events.clear();

    Events = Fileparser->GetFileContent(ui->CheckFileLine->text().toStdString());
    int SizeChecker = Fileparser->CheckSize();

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


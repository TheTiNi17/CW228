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

void MainWindow::updateTime()
{
    ui->label->setText(QTime::currentTime().toString());
}

void MainWindow::on_TrackingButton_clicked()
{


}


void MainWindow::on_CheckFileButton_clicked()
{
    ui->AllEventsOutput->setText("");

    ui->TrackingButton->setEnabled(false);
    Events.clear();
    Events = fileparser.FileContent(ui->CheckFileLine->text().toStdString());

    switch(fileparser.Check())
    {
        case 1: // файл не алё
            ErrorMsgBox.setIcon(QMessageBox::Critical);
            ErrorMsgBox.setWindowTitle("Critical!");
            ErrorMsgBox.setText("Не удалось открыть файл!");
            ErrorMsgBox.exec();
            break;
        case 4: // ивентов от 5 до 30, но не 20 НЕКРИТИЧ
            ErrorMsgBox.setIcon(QMessageBox::Warning);
            ErrorMsgBox.setWindowTitle("Warnig!");
            ErrorMsgBox.setText("Неправильный размер!");
            ErrorMsgBox.exec();
            ui->TrackingButton->setEnabled(true);
            break;
        case 5: // ивентов меньше 5 или больше 30 КРИТИЧ
            ErrorMsgBox.setIcon(QMessageBox::Critical);
            ErrorMsgBox.setWindowTitle("Critical!");
            ErrorMsgBox.setText("Неправильный размер!");
            ErrorMsgBox.exec();
            break;
        case 2: // Много слов в описании
        case 3: // 3 элемент не число
            ui->TrackingButton->setEnabled(true);
            break;
        case 0:
            ui->TrackingButton->setEnabled(true);
            break;

    }
    if (ui->TrackingButton->isEnabled())
    {
        for (int i = 0; i < Events.size(); i++)
        {
            ui->AllEventsOutput->append(QString::fromStdString("№ " + std::to_string(i + 1) + ": " + Events.at(i).ReturnPrint()));
        }
    }
}


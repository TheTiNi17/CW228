#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

#include "eventtimegenerator.h"
#include "fileparser.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void PrintEvents();
    void PrintEventsWithTime();
    int EventActualityChecker(int NumberOfEvent);

    Ui::MainWindow *ui;
    QTimer *Timer;
    FileParser *Fileparser;
    EventTimeGenerator *Generator;

    std::vector<Event> Events;
    QMessageBox ErrorMsgBox;
    QTime EndOfExecution;

private slots:
    void updateTime();
    void UpdateActiveEvents();
    void on_TrackingButton_clicked();
    void on_CheckFileButton_clicked();
};
#endif // MAINWINDOW_H

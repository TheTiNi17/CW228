#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

#include "eventgenerator.h"
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
    QMessageBox ErrorMsgBox;
    Ui::MainWindow *ui;
    QTimer *tmr;
    FileParser fileparser;
    std::vector <Event> Events;
private slots:
    void updateTime();
    void on_TrackingButton_clicked();
    void on_CheckFileButton_clicked();
};
#endif // MAINWINDOW_H

#include "userwindow.h"
#include "ui_userwindow.h"
#include <iostream>
#include <QDateTime>
#include <QTimer>

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    if(!timer)
        return;
    timer->setInterval(60000);
    working = false;
    connect(ui->pushButton_work,SIGNAL(clicked()),this,SLOT(Work()));
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateWorkTime()));
}

UserWindow::~UserWindow()
{
    if(workStart)
        delete workStart;
    delete timer;
    delete ui;
}

void UserWindow::Work()
{
    if(working)
    {
        ui->pushButton_work->setText("Start working");
        int sec = workStart->secsTo(QDateTime::currentDateTime());
        int minutes = sec/60;
        int hours = minutes/60;
        minutes = minutes % 60;
        std::clog<<"Working time: "<< hours << ":" << minutes <<std::endl;
        delete workStart;
        workStart = NULL;
        timer->stop();
        working = false;
    }
    else
    {
        std::clog<<"UserWindow::Work(), working = false"<<std::endl;
        workStart = new QDateTime(QDateTime::currentDateTime());
        if(!workStart)
            return;
        timer->start();
        ui->pushButton_work->setText("Stop working");
        std::clog<<workStart->toString().toStdString()<<std::endl;
        working = true;
        ui->lcdNumber_worktime->display("0:00");
    }
}

void UserWindow::UpdateWorkTime()
{
    int sec = workStart->secsTo(QDateTime::currentDateTime());
    int minutes = sec/60;
    int hours = minutes/60;
    minutes = minutes % 60;
    QVariant min(minutes);
    QVariant h(hours);
    QString s = h.toString() + ":";
    if(minutes < 9)
        s += "0";
    s += min.toString();
    ui->lcdNumber_worktime->display(s);
    std::clog<<"UpdateLCD"<<std::endl;
}

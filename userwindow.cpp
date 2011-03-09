#include "userwindow.h"
#include "ui_userwindow.h"
#include <iostream>
#include <QDateTime>

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    working = false;
    connect(ui->pushButton_work,SIGNAL(clicked()),this,SLOT(Work()));
}

UserWindow::~UserWindow()
{
    delete workStart;
    delete ui;
}

void UserWindow::Work()
{
    if(working)
    {
        ui->pushButton_work->setText("Start working");
        delete workStart;
        working = false;
    }
    else
    {
        std::clog<<"UserWindow::Work(), working = false"<<std::endl;
        workStart = new QDateTime(QDateTime::currentDateTime());
        if(!workStart)
            return;
        ui->pushButton_work->setText("Stop working");
        std::clog<<workStart->toString().toStdString()<<std::endl;
        working = true;
    }
}

#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QDateTime>

namespace Ui {
    class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = 0);
    ~UserWindow();

public slots:
    void Work();

private:
    Ui::UserWindow *ui;
    QDateTime* workStart;
    bool working;
};

#endif // USERWINDOW_H

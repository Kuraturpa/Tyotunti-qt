#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>

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
    void UpdateWorkTime();

private:
    Ui::UserWindow *ui;
    QDateTime* workStart;
    bool working;
    QTimer* timer;
};

#endif // USERWINDOW_H

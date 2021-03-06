#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "help.h"
#include "plot.h"
#include "table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    help *h; //declare pointer to help class
    plot *p; //pointer to plot class
    table *t; //pointer to table class

    bool dataCheck(double *r25, double *bVal, double *rFixed, bool *orient);

    void computeRes(QVector<double>& temp, QVector<double>& res, int numElems, double r25, double bVal);
};

#endif // MAINWINDOW_H

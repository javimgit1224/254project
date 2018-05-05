#include "plot.h"
#include "ui_plot.h"
#include <qdebug.h>

plot::plot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plot)
{
    ui->setupUi(this);
}

plot::~plot()
{
    delete ui;
}


void plot::plotCurve(double r25, double bVal, double rFixed, int orientation)
{
    qDebug() << r25 << ", " << bVal << ", " << rFixed << ", " << orientation << endl;
}

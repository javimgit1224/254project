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


void plot::plotCurve(QVector<double> &x, QVector<double> &y, int numElems)
{
    double yMin = 0;
    double yMax = y[0];
    if(y[numElems-1]> yMax)
        yMax = y[numElems-1];

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setRange(0, 101);
    ui->customPlot->yAxis->setRange(yMin, yMax);
    ui->customPlot->xAxis->setLabel("Temperature");
    ui->customPlot->yAxis->setLabel("Vout");
}

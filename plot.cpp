#include "plot.h"
#include "ui_plot.h"
#include <qdebug.h>
#include <QString>

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


void plot::plotCurve(QVector<double> &x, QVector<double> &y, int numElems, int min, double r25, double bVal, double rFixed, bool orientation)
{
    QString buff;
    double yMin = 0;
    double yMax = y[0];
    if(y[numElems-1]> yMax)
        yMax = y[numElems-1];
    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setRange(min, numElems+min);
    ui->customPlot->yAxis->setRange(yMin, yMax);
    ui->customPlot->xAxis->setLabel("Temperature(C)");
    ui->customPlot->yAxis->setLabel("Vout(%Vin)");
    ui->customPlot->graph(0)->setData(x, y);


    //side labels
    buff = "R25 = ";
    buff.append(QString::number(r25, 'f', 0));
    ui->label->setText(buff);
    buff = "Bval = ";
    buff.append(QString::number(bVal, 'f', 0));
    ui->label_2->setText(buff);
    if(orientation == 0)
        buff = "Rtherm = R1";
    else
        buff = "Rtherm = R2";
    ui->label_3->setText(buff);
    if(orientation == 0)
        buff = "R2 = ";
    else
        buff = "R1 = ";
    buff.append(QString::number(rFixed, 'f', 0));
    ui->label_4->setText(buff);
}

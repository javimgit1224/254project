#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <stdlib.h>
#include <QtMath>

#include <QDebug> //qDebug() << equivalent to cout <<


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//this is for the first radio button
//we want an image to open up on screen to display which R-therm user chose
void MainWindow::on_radioButton_clicked()
{
    //Clear any error messages:
    ui->label_5->setText("");
    char * currentDir = getenv("PWD");
    char  buffer[150] = {0};
    strcat(buffer, currentDir);
    //this path assumes manual placement of the .jpg in the build folder
    //it is not a good solution, but is easy to implement
    strcat(buffer, "/build-254-Desktop_Qt_5_7_0_GCC_64bit-Debug/RthermR1_schem.jpg");
    //create a pic and chose the path of the pic
    QPixmap pix(buffer);
    //use an if statement to state if the button is clicked display the pic
    if (ui->radioButton->isChecked())
       ui->label_4->setPixmap(pix);

}

//same as above
void MainWindow::on_radioButton_2_clicked()
{
    //Clear any error messages:
    ui->label_5->setText("");
    char * currentDir = getenv("PWD");
    char  buffer[150] = {0};
    strcat(buffer, currentDir);
    //this path assumes manual placement of the .jpg in the build folder
    //it is not a good solution, but is easy to implement
    strcat(buffer, "/build-254-Desktop_Qt_5_7_0_GCC_64bit-Debug/RthermR2_schem.jpg");
    QPixmap pix2(buffer);
    if(ui->radioButton_2->isChecked())
        ui->label_4->setPixmap(pix2);
}

//when user clicks on the graph button it will open a new window
void MainWindow::on_pushButton_clicked()
{
    bool orient;
    bool canPlot;
    double r25 = 0;
    double bVal = 0;
    double rFixed = 0;
    //102 data points calculated from -2 to 100
    //start at -2 to avoid graphing issues
    int vecSize = 202;
    QVector<double> x(vecSize+1), y(vecSize+1);
    int i = 0;


    //Check data reqs
    canPlot = dataCheck(&r25, &bVal, &rFixed, &orient);
    //If we failed then exit
    if(canPlot == false)
        return;

    //Values are ok, lets make a data set.
    for(i = 0; i < vecSize; i++)
        x[i] = i-2;
    //Calculate resistances based on thermistor data
    computeRes(x, y, vecSize, r25, bVal);
    //Calculate Vout as a ratio of Vin by using
    //orientation of voltage divider and fixed resistor value
    if(orient == false)//Rtherm == R1
    {
        for(i = 0; i < vecSize; i++)
        {
            y[i] = rFixed/(rFixed + y[i]);
        }
    }
    else//Rtherm == R2
    {
        for(i = 0; i < vecSize; i++)
        {
            y[i] = y[i]/(y[i] + rFixed);
        }
    }


    //Create dialogue
    p = new plot(this);
    p->show();

    //Plot
    p->plotCurve(x, y, vecSize, r25, bVal, rFixed, orient);
}

//when user clicks on the table button it will open a new window
void MainWindow::on_pushButton_2_clicked()
{
    QString buffer;
    buffer = ui->lineEdit->text();
    qDebug() << buffer << endl;

    buffer = ui->lineEdit_2->text();
    qDebug() << buffer << endl;


    buffer = ui->lineEdit_3->text();
    qDebug() << buffer << endl;
    return;
}

//when user clicks on the help button it will open a new window
void MainWindow::on_pushButton_3_clicked()
{
    h = new help(this);
    h->show();
}


bool MainWindow::dataCheck(double* r25, double* bVal, double* rFixed, bool* orient)
{
    bool canPlot = true;

    //grab a number from each lineEdit, if it
    //is not a number, return
    *r25 = ui->lineEdit->text().toDouble(orient);
    if(*orient == false)
    {
        canPlot = false;
        ui->lineEdit->setText("Enter a number.");
    }
    *bVal = ui->lineEdit_2->text().toDouble(orient);
    if(*orient == false)
    {
        canPlot = false;
        ui->lineEdit_2->setText("Enter a number.");
    }
    *rFixed = ui->lineEdit_3->text().toDouble(orient);
    if(*orient == false)
    {
        canPlot = false;
        ui->lineEdit_3->setText("Enter a number.");
    }

    if(ui->radioButton->isChecked())
        *orient = false;
    else if(ui->radioButton_2->isChecked())
        *orient = true;
    else
    {
        canPlot = false;
        ui->label_5->setText("Choose one of the options.");
    }

    return canPlot;
}

void MainWindow::computeRes(QVector<double>& temp, QVector<double>& res, int numElems, double r25, double bVal)
{
    double t0 = 25+273.15; //Temp that R0 is measured in kelvin

    for(int i = 0; i < numElems; i++)
    {
        res[i]=r25*qExp(-bVal*(1/t0-1/(temp[i]+273.15)));
    }
}

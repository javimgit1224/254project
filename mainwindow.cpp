#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <stdlib.h>

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
    char * currentDir = getenv("PWD");
    char  buffer[150] = {0};
    strcat(buffer, currentDir);
    strcat(buffer, "/build-254-Desktop_Qt_5_7_0_GCC_64bit-Debug/RthermR1_schem.jpg");
    printf("%s\n",buffer);
    //create a pic and chose the path of the pic
    QPixmap pix(buffer);
    //use an if statement to state if the button is clicked display the pic
    if (ui->radioButton->isChecked())
       ui->label_4->setPixmap(pix);

}

//same as above
void MainWindow::on_radioButton_2_clicked()
{
    char * currentDir = getenv("PWD");
    char  buffer[150] = {0};
    strcat(buffer, currentDir);
    strcat(buffer, "/build-254-Desktop_Qt_5_7_0_GCC_64bit-Debug/RthermR2_schem.jpg");
    QPixmap pix2(buffer);
    if(ui->radioButton_2->isChecked())
        ui->label_4->setPixmap(pix2);
}
//when user clicks on the help button it will open a new window
void MainWindow::on_pushButton_3_clicked()
{
    h = new help(this);
    h->show();

}

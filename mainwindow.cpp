#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    //create a pic and chose the path of the pic
    QPixmap pix("/home/javi/Desktop/r1.jpg");
    //use an if statement to state if the button is clicked display the pic
    if (ui->radioButton->isChecked())
       ui->label_4->setPixmap(pix);

}

//same as above
void MainWindow::on_radioButton_2_clicked()
{
    QPixmap pix2("/home/javi/Desktop/r2.jpg");
    if(ui->radioButton_2->isChecked())
        ui->label_4->setPixmap(pix2);
}

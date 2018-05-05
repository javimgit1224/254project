#include "table.h"
#include "ui_table.h"
#include <QString>

table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
}

table::~table()
{
    delete ui;
}

void table::printTable(QVector<double> res, int numElems, int tempMin, int stepPerIter)
{
    if (numElems < stepPerIter)
        ui->plainTextEdit->appendPlainText("Error: not enough table elements.");

    int i;
    int currentTemp = tempMin;
    QString buff;


    //Set up table
    ui->plainTextEdit->appendPlainText(
    "//This table is used for determining resistance values in a\n"
    "//quick way using linear interpolation\n"
    "//between data points."
    );
    //insert table size constant
    buff = "#define TABLE_ROWS ";
    buff.append(QString::number(numElems/stepPerIter+1, 'f', 0));
    ui->plainTextEdit->appendPlainText(buff);
    //insert table delcaration
    ui->plainTextEdit->appendPlainText(
    "const double tempResTable[TABLE_ROWS][2] =\n"
    "{"
    );

    //Fill in elements
    for(i = 0; i <= numElems; i+=stepPerIter)
    {
        buff = "    {";
        buff.append(QString::number(currentTemp, 'f', 0));
        buff.append(", ");
        buff.append(QString::number(res[i], 'f', 6));
        if(i+stepPerIter <= numElems)
            buff.append("},");
        else
            buff.append("}"); //last entry does not need a comma
        //appendPlainText automatically inserts newline
        ui->plainTextEdit->appendPlainText(buff);
        currentTemp += stepPerIter;
    }
    ui->plainTextEdit->appendPlainText("};\n\n");

    //Search algorithm
    ui->plainTextEdit->appendPlainText(
    "//This function, given a certain resistance and a table\n"
    "//formatted above to search through, searches the\n"
    "//table and returns a temperature.\n"
    "double tableSearch(double res, const double tab[][2],const int rows)\n"
    "{\n"
    "   double slope;\n"
    "   double xOffset;\n"
    "   double yOffset;\n"
    "   int i;\n"
    "   \n"
    "   if(res > tab[0][1])\n"
    "   {\n"
    "       slope = (tab[1][0]-tab[0][0])/(tab[1][1]-tab[0][1]);\n"
    "       xOffset = res-tab[0][1];\n"
    "       yOffset = tab[0][0];\n"
    "   }\n"
    "   else if(res < tab[rows-1][1])\n"
    "   {\n"
    "       slope = (tab[rows-1][0]-tab[rows-2][0])/\n"
    "                   (tab[rows-1][1]-tab[rows-2][1]);\n"
    "       xOffset = res - tab[rows-2][1];\n"
    "       yOffset = tab[rows-2][0];\n"
    "   }\n"
    "   else\n"
    "   {\n"
    "       i = 0;\n"
    "       while(res < tab[i][1])\n"
    "       {\n"
    "           i++;\n"
    "       }\n"
    "       slope = (tab[i][0]-tab[i-1][0])/(tab[i][1]-tab[i-1][1]);\n"
    "       xOffset = res - tab[i-1][1];\n"
    "       yOffset = tab[i-1][0];\n"
    "   }\n"
    "\n"
    "   return xOffset*slope + yOffset;\n"
    "}");
}

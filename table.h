#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QVector>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();

    void printTable(QVector<double> res, int numElems, int tempMin, int stepPerIter);

private:
    Ui::table *ui;
};

#endif // TABLE_H

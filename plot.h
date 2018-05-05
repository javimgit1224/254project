#ifndef PLOT_H
#define PLOT_H

#include <QDialog>
#include <QVector>

namespace Ui {
class plot;
}

class plot : public QDialog
{
    Q_OBJECT

public:
    explicit plot(QWidget *parent = 0);
    ~plot();

    void plotCurve(QVector<double>& x, QVector<double>& y, int numElems, double r25, double bVal, double rFixed, bool orientation);

private:
    Ui::plot *ui;
};

#endif // PLOT_H

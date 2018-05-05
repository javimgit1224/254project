#ifndef PLOT_H
#define PLOT_H

#include <QDialog>

namespace Ui {
class plot;
}

class plot : public QDialog
{
    Q_OBJECT

public:
    explicit plot(QWidget *parent = 0);
    ~plot();

    void plotCurve(double r25, double bVal, double rFixed, int orientation);

private:
    Ui::plot *ui;
};

#endif // PLOT_H

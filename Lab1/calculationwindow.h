#ifndef CALCULATIONWINDOW_H
#define CALCULATIONWINDOW_H

#include <QDialog>
#include "shapes.h"

namespace Ui {
class CalculationWindow;
}

class CalculationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalculationWindow(QWidget *parent = nullptr, const QString &figure = "");
    ~CalculationWindow();

private slots:
    void calculateArea();
    void setShapeImage(const QString &shape);
    void setFormula(const QString &shape);
    void on_buttClean_clicked();

private:
    Ui::CalculationWindow *ui;
    Shapes shapes;
    QString figure;
};

#endif // CALCULATIONWINDOW_H

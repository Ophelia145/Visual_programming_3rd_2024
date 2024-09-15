#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculationwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSquareWindow();
    void openRectangleWindow();
    void openParallelogramWindow();
    void openRhombusWindow();
    void openTriangleWindow();
    void openTrapezoidWindow();
    void openCircleWindow();
    void openSectorWindow();

    void on_buttAut_clicked();


private:
    Ui::MainWindow *ui;
    CalculationWindow* createCalculationWindow(const QString &figure);
};

#endif // MAINWINDOW_H

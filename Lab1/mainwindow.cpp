#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->square, &QPushButton::clicked, this, &MainWindow::openSquareWindow);
    connect(ui->rectangle, &QPushButton::clicked, this, &MainWindow::openRectangleWindow);
    connect(ui->parallelogram, &QPushButton::clicked, this, &MainWindow::openParallelogramWindow);
    connect(ui->rhombus, &QPushButton::clicked, this, &MainWindow::openRhombusWindow);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::openTriangleWindow);
    connect(ui->trapezoid, &QPushButton::clicked, this, &MainWindow::openTrapezoidWindow);
    connect(ui->circle, &QPushButton::clicked, this, &MainWindow::openCircleWindow);
    connect(ui->sector, &QPushButton::clicked, this, &MainWindow::openSectorWindow);

    connect(ui->buttaut, &QPushButton::clicked, this, &MainWindow::on_buttAut_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSquareWindow()
{
    CalculationWindow *window = createCalculationWindow("Square");
    window->show();
}

void MainWindow::openRectangleWindow()
{
    CalculationWindow *window = createCalculationWindow("Rectangle");
    window->show();
}

void MainWindow::openParallelogramWindow()
{
    CalculationWindow *window = createCalculationWindow("Parallelogram");
    window->show();
}

void MainWindow::openRhombusWindow()
{
    CalculationWindow *window = createCalculationWindow("Rhombus");
    window->show();
}

void MainWindow::openTriangleWindow()
{
    CalculationWindow *window = createCalculationWindow("Triangle");
    window->show();
}

void MainWindow::openTrapezoidWindow()
{
    CalculationWindow *window = createCalculationWindow("Trapezoid");
    window->show();
}

void MainWindow::openCircleWindow()
{
    CalculationWindow *window = createCalculationWindow("Circle");
    window->show();
}

void MainWindow::openSectorWindow()
{
    CalculationWindow *window = createCalculationWindow("Sector");
    window->show();
}

CalculationWindow* MainWindow::createCalculationWindow(const QString &figure)
{
    return new CalculationWindow(this, figure);
}

void MainWindow::on_buttAut_clicked()
{
    QMessageBox::information(this, "Авторы", "ИП-213 Хайбулаева Алиса");
}



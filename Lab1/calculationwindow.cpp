#include "calculationwindow.h"
#include "ui_calculationwindow.h"
#include "shapes.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>


CalculationWindow::CalculationWindow(QWidget *parent, const QString &figure) :
    QDialog(parent),
    ui(new Ui::CalculationWindow),
    figure(figure)
{
    ui->setupUi(this);

    if (figure == "Square") {
        ui->label->setText("Enter side length");
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
    } else if (figure == "Rectangle" || (figure == "Parallelogram" || figure == "Triangle")) {
        ui->label->setText("Enter base and height");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(false);
    } else if (figure == "Rhombus") {
        ui->label->setText("Enter diagonals");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(false);
    } else if (figure == "Circle") {
        ui->label->setText("Enter radius");
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
    } else if (figure == "Sector") {
        ui->label->setText("Enter radius and angle");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(false);
    } else if (figure == "Trapezoid") {
        ui->label->setText("Enter base1, base2 and diagonal");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
    }

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &CalculationWindow::calculateArea);
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, this, &CalculationWindow::calculateArea);
    connect(ui->lineEdit_3, &QLineEdit::returnPressed, this, &CalculationWindow::calculateArea);
    setFormula(figure);

    connect(ui->pushButton, &QPushButton::clicked, this, &CalculationWindow::on_buttClean_clicked);

}
void CalculationWindow::on_buttClean_clicked()
{
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->label_2->clear();

}

CalculationWindow::~CalculationWindow()
{
    delete ui;
}

void CalculationWindow::calculateArea()
{
    double result = 0;

    double input1 = ui->lineEdit->text().toDouble();
    double input2 = ui->lineEdit_2->text().toDouble();
    double input3 = ui->lineEdit_3->text().toDouble();

    if (figure == "Square") {
        result = shapes.square(input1);
    } else if (figure == "Rectangle") {
        result = shapes.rectangle(input1, input2);
    } else if (figure == "Triangle") {
        result = shapes.triangle(input1, input2);
    }
    else if (figure == "Parallelogram") {
        result = shapes.parallelogram(input1, input2);
    } else if (figure == "Rhombus") {
        result = shapes.rhombus(input1, input2);
    } else if (figure == "Circle") {
        result = shapes.circle(input1);
    } else if (figure == "Sector") {
        result = shapes.sector(input1, input2);
    } else if (figure == "Trapezoid") {
        result = shapes.trapezoid(input1, input2, input3);
    }

    ui->label->setText("Area: " + QString::number(result));

}


void CalculationWindow::setShapeImage(const QString &shape)
{
    QPixmap pixmap;
    if (shape == "Square") {
        pixmap.load(":/i/squar.jfif");
    } else if (shape == "Circle") {
        pixmap.load(":/i/circle.jfif");
    } else if (shape == "Triangle") {
        pixmap.load(":/i/triang.png");
    } else if (shape == "Sector") {
        pixmap.load(":/i/sec.png");
    } else if (shape == "Parallelogram") {
            pixmap.load(":/i/par.png");
    }  else if (shape == "Trapezoid") {
        pixmap.load(":/i/trap.jfif");
    }  else if (shape == "Rectangle") {
        pixmap.load(":/i/rect.png");
    }  else if (shape == "Rhombus") {
        pixmap.load(":/i/rho.jpg");
    }


    if (!pixmap.isNull()) {
        ui->label_2->setPixmap(pixmap);
    } else {
        qDebug() << "Failed to load image for shape: " << shape;
    }
}

void CalculationWindow::setFormula(const QString &shape)
{
    QString formula;

    if (shape == "Square") {
        formula = "Area = a^2";
    } else if (shape == "Rectangle") {
        formula = "Area = a × b";
    } else if (shape == "Triangle") {
        formula = "Area = (1/2)× base × height";
    } else if (shape == "Parallelogram") {
        formula = "Area = base × height";
    } else if (shape == "Rhombus") {
        formula = "Area = (1/2) × d1 × d2";
    } else if (shape == "Circle") {
        formula = "Area = π × r^2";
    } else if (shape == "Sector") {
        formula = "Area = (1/2) × r^2 × θ";
    } else if (shape == "Trapezoid") {
        formula = "Area = (1/2) × (a + b) × h";
    }

    ui->label_7->setText(formula);
}

#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
int main(int argc, char *argv[]) //кол-во арг; сами строки аргументов
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QLabel *inscription = new QLabel("Выбор фигуры для нахождения площади");
    //inscription->show();
    return a.exec(); //главный цикл обработки событий
}


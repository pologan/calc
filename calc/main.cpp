#include "mainwindow.h"
#include <QApplication>
#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include "parser.h"

using namespace std;

float _add(float arg1, float arg2)
{
    return arg1 + arg2;
}

float _subtract(float arg1, float arg2)
{
    return arg1 - arg2;
}

float _multiply(float arg1, float arg2)
{
    return arg1 * arg2;
}

float _division(float arg1, float arg2)
{
    return arg1 / arg2;
}

float _power(float arg1, float arg2)
{
    return powf(arg1,arg2);
}

int main(int argc, char *argv[])
{
    parser p;
    p.AddOperator("+", 1, ( direction ) 0, _add);
    p.AddOperator("-", 1, ( direction ) 0, _subtract);
    p.AddOperator("*", 2, ( direction ) 0, _multiply);
    p.AddOperator("/", 2, ( direction ) 0, _division);
    p.AddOperator("^", 3, (direction ) 0, _power);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

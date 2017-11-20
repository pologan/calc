#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_equalButton_clicked()
{
    QString fun = ui->lineEdit->text();
    int res = 0;
    for(int i=0;i<fun.length();i++)
    {
        if(fun[i] == 'x')
        {
            res *= 3;
        }
        if(fun[i]>= '0' || fun[i]<='9')
        {

        }
    }
}

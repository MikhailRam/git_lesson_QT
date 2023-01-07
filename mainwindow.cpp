#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_signbefore, SIGNAL(clicked()), this, SLOT(operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button =(QPushButton *) sender();

    double all_numbers;
    QString new_lable;
    all_numbers = (ui->result_show->text() + button->text()).toDouble();
    new_lable = QString::number(all_numbers, 'g', 15);

    ui->result_show->setText(new_lable);
}

void MainWindow::on_pushButton_comma_clicked()
{
    if(ui->result_show->text().contains('.'))
    ui->result_show->setText(ui->result_show->text() + ".");

}

void MainWindow::operations()
{
    QPushButton *button =(QPushButton *) sender();
    double all_numbers;
    QString new_lable;

    if(button->text() == "+/-"){
        all_numbers = (ui->result_show->text().toDouble());
        all_numbers = all_numbers * -1;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_lable);
    }
}


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
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button =(QPushButton *) sender();
    double all_numbers;
    QString new_string;


    if(ui->result_show->text().contains(".") && button->text() == "0"){
        new_string = ui->result_show->text() + button->text();
        ui->result_show->setText(new_string);
    }else{
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        output(all_numbers);
    }
    if(ui->result_show->text().size() != 0){
        ui->pushButton_del->setText("C");
    }
}

void MainWindow::on_pushButton_comma_clicked()
{
    if(!(ui->result_show->text().contains('.')))
    {
        ui->result_show->setText(ui->result_show->text() + ".");
    }

}

void MainWindow::operations()
{
    QPushButton *button =(QPushButton *) sender();
    double all_numbers;

    all_numbers = (ui->result_show->text().toDouble());

    if(button->text() == "+/-"){
        all_numbers = all_numbers * -1;
        output(all_numbers);
    }
    else if(button->text() == "%"){
        all_numbers = all_numbers * 0.01;
    }

    output(all_numbers);
}

void MainWindow::math_operations()
{
    QPushButton *button =(QPushButton *) sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");

    button->setChecked(true);

}


void MainWindow::on_pushButton_del_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    ui->pushButton_del->setText("AC");

    ui->result_show->setText("0");
}


void MainWindow::on_pushButton_equals_clicked()
{
    double lableNumber, num_second;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        lableNumber = num_first + num_second;

        output(lableNumber);

        ui->pushButton_plus->setChecked(false);

    } else if(ui->pushButton_minus->isChecked()){
        lableNumber = num_first - num_second;

        output(lableNumber);

        ui->pushButton_plus->setChecked(false);

    } else if(ui->pushButton_divide->isChecked()){

        if(num_second == 0){
            ui->result_show->setText("Error");
        } else{
            lableNumber = num_first / num_second;

            output(lableNumber);

            ui->pushButton_plus->setChecked(false);
        }

    } else if(ui->pushButton_multiply->isChecked()){

        lableNumber = num_first * num_second;

        output(lableNumber);

        ui->pushButton_plus->setChecked(false);

    }



}

void MainWindow::output(const double lableNumber){
    QString new_lable;

    new_lable = QString::number(lableNumber, 'g', 15);
    ui->result_show->setText(new_lable);

}

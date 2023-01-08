#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double num_first;

private:
    Ui::MainWindow *ui;

    void output(const double lableNumber);

private slots:
    void digits_numbers();
    void on_pushButton_comma_clicked();
    void operations();
    void on_pushButton_del_clicked();
    void on_pushButton_equals_clicked();
    void math_operations();
};
#endif // MAINWINDOW_H

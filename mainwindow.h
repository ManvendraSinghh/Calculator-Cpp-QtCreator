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

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_decimal_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_equals_released();
    void binary_operation_pressed();
    void delete_button_pressed();
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstnum;
bool useristypingsecondnumber = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_14,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->delete_button,SIGNAL(released()),this,SLOT(delete_button_pressed()));
    connect(ui->modulus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(on_pushButton_clear_released()));
    connect(ui->addition,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->Substraction,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->Multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->equals,SIGNAL(released()),this,SLOT(on_equals_released()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button =(QPushButton*)sender();
    QString newLabel;
    double labelnumber;

    if ((ui->addition->isChecked() || ui->Substraction->isChecked() ||
         ui->Multiply->isChecked() || ui->divide->isChecked()) && (!useristypingsecondnumber))
    {
        labelnumber = button->text().toDouble();
        useristypingsecondnumber = true;
        newLabel = QString::number(labelnumber,'g',15);
    }
    else{
        if(ui->label->text().contains('.') && button->text()=="0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label->text() + button->text()).toDouble();
             newLabel = QString::number(labelnumber,'g',15);
        }
          }
    ui->label->setText(newLabel);
    ui->addition->setCheckable(true);
    ui->Substraction->setCheckable(true);
    ui->divide->setCheckable(true);
    ui->Multiply->setCheckable(true);

}

void MainWindow::on_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;
    double labelnumber;

    if ( button->text()=="%" )
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = labelnumber * 0.01;
        newLabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newLabel);
    }

    useristypingsecondnumber = false;
}


void MainWindow::on_pushButton_clear_released()
{
    ui->addition->setChecked(false);
    ui->Substraction->setChecked(false);
    ui->Multiply->setChecked(false);
    ui->divide->setChecked(false);
    useristypingsecondnumber=false;
    ui->label->setText("0");
}

void MainWindow::delete_button_pressed()
{
    QString currentText = ui->label->text();
    if (!currentText.isEmpty()) {
        currentText.chop(1); // Remove the last character
        ui->label->setText(currentText);
    }
}


void MainWindow::on_equals_released()
{
    double labelnumber,secondnum;
    QString newlabel;

    secondnum = ui->label->text().toDouble();

    if ( ui->addition->isChecked())
    {
        labelnumber = firstnum + secondnum ;
        newlabel =  QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->addition->setChecked(false);
    }
    else if ( ui->Substraction->isChecked())
    {
        labelnumber = firstnum - secondnum ;
        newlabel =  QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->Substraction->setChecked(false);
    }
    else if ( ui->Multiply->isChecked())
    {
        labelnumber = firstnum * secondnum ;
        newlabel =  QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->Multiply->setChecked(false);
    }
    else if ( ui->divide->isChecked())
    {
        labelnumber = firstnum / secondnum ;
        newlabel =  QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->divide->setChecked(false);
    }

    useristypingsecondnumber=false;

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstnum = ui->label->text().toDouble();

    button->setChecked(true);

}


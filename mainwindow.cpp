#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    difficulty=1;
    ui->setupUi(this);
    cmine=new Cmine(this,9,9,10);
    ui->horizontalLayout->insertWidget(0,cmine);
    ui->label_2->setText(QString::number(cmine->count));
    connect(cmine,SIGNAL(sig_lost()),this,SLOT(slot_lost()));
    connect(cmine,SIGNAL(sig_count()),this,SLOT(slot_count()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_lost()
{
    ui->label_3->setText("you lost it !!!");
}

void MainWindow::slot_count()
{
    ui->label_2->setText(QString::number(cmine->count));
    if(cmine->count==0)
    {
        ui->label_3->setText("you got it !!!");
    }
}

void MainWindow::on_pushButton_clicked()
{
    Cmine* _cmine=new Cmine(this,cmine->row,cmine->col,cmine->num_mine,cmine->d);
    delete cmine;
    cmine=_cmine;
    ui->horizontalLayout->insertWidget(0,cmine);
    ui->label_2->setText(QString::number(cmine->count));
    connect(cmine,SIGNAL(sig_lost()),this,SLOT(slot_lost()));
    connect(cmine,SIGNAL(sig_count()),this,SLOT(slot_count()));
    ui->label_3->setText("");
    //update();
}

void MainWindow::on_pushButton_2_clicked()
{
    switch (difficulty)
    {
    case 1:
    {
        Cmine* _cmine=new Cmine(this,16,16,40);
        delete cmine;
        cmine=_cmine;
        ui->horizontalLayout->insertWidget(0,cmine);
        ui->label_2->setText(QString::number(cmine->count));
        connect(cmine,SIGNAL(sig_lost()),this,SLOT(slot_lost()));
        connect(cmine,SIGNAL(sig_count()),this,SLOT(slot_count()));
        ui->label_3->setText("");
        difficulty++;
        break;
    }
    case 2:
    {
        Cmine* _cmine=new Cmine(this,24,20,99);
        delete cmine;
        cmine=_cmine;
        ui->horizontalLayout->insertWidget(0,cmine);
        ui->label_2->setText(QString::number(cmine->count));
        connect(cmine,SIGNAL(sig_lost()),this,SLOT(slot_lost()));
        connect(cmine,SIGNAL(sig_count()),this,SLOT(slot_count()));
        ui->label_3->setText("");
        difficulty++;
        break;
    }
    case 3:
    {
        Cmine* _cmine=new Cmine(this,9,9,10);
        delete cmine;
        cmine=_cmine;
        ui->horizontalLayout->insertWidget(0,cmine);
        ui->label_2->setText(QString::number(cmine->count));
        connect(cmine,SIGNAL(sig_lost()),this,SLOT(slot_lost()));
        connect(cmine,SIGNAL(sig_count()),this,SLOT(slot_count()));
        ui->label_3->setText("");
        difficulty=1;
        break;
    }
    default:
        break;
    }
}

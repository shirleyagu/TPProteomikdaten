#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QTableView"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(5,12,this); //Erstellt eine Tabelle mit 5 Zeilen und 12 Spalten

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Number")));        //Legt die Spaltenüberschriften Fest wie auf dem ÜB vorgegeben
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Stern")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("PI")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Accession")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Description")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("Chr")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("Coverage")));
    model->setHorizontalHeaderItem(7, new QStandardItem(QString("#Peptides")));
    model->setHorizontalHeaderItem(8, new QStandardItem(QString("#Spectra")));
    model->setHorizontalHeaderItem(9, new QStandardItem(QString("Quant")));
    model->setHorizontalHeaderItem(10, new QStandardItem(QString("MW")));
    model->setHorizontalHeaderItem(11, new QStandardItem(QString("Confidence")));
    model->setHorizontalHeaderItem(12, new QStandardItem(QString("Check")));

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

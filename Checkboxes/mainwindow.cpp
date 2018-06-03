#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QTableWidgetItem"
#include "QCheckBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const int rows = 5;
    const int columns = 7;
    const int check = 6;
        
    // Stringlisten für die Überschriften der Tabellen
    QStringList Header1 = {"#","...","pi","Accession","Description","Chr","Coverage","#Peptides","#Spectra","MS2 Quant","MW","Confidence","Check"};
    QStringList Header2 = {"#","...","Sequence","Start","#Spectra","Confidence","Check"};
    
     //Constructor der Tabelle
    QStandardItemModel *model = new QStandardItemModel(rows,columns,this); //Erstellt eine Tabelle mit 5 Zeilen und 12 Spalten
    for (int i= 0; i < columns; i++){                                                       //Einfügen der Header
        model->setHorizontalHeaderItem(i, new QStandardItem(QString (Header2.at(i))));
    }

    for (int i=0; i< rows;i++){                                                              //Einfügen der Checkboxen
    QStandardItem* item0 = new QStandardItem(true);
    item0->setCheckable(true);
    item0->setCheckState(Qt::Checked);
    model->setItem(i, check, item0);
    }

    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);                          
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

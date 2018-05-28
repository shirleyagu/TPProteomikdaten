#include<QApplication>
#include<QTableView>
#include "mytable.h"

int main(int argc, char *argv[]){

    QApplication app(argc,argv);
    QTableView table; //create instance of QTableView
    MyModel myModel(0);
    table.resize(1500,400);
    table.resizeColumnsToContents();
    table.setModel(&myModel); //set Model
    table.show(); //show table
    return app.exec();
}

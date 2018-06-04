#include "delegate.h"

#include <QApplication>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStandardItemModel model(10, 8);
    QTableView tableView;
    tableView.setModel(&model);

    CheckBoxDelegate delegate;
    tableView.setItemDelegate(&delegate);

    //set header labels
    QString headerlabels[8]={"","","PI","Sequence","Start","#Spectra","Confidence",""};
    for (int i=0;i<sizeof(headerlabels)/sizeof(headerlabels[0]);i++){
    model.setHeaderData(i,Qt::Horizontal,headerlabels[i]);
    }


    for (int row = 0; row < 10; ++row) {

        for (int column=0;column<1;column++) {
            QModelIndex index = model.index(row, column, QModelIndex());
            model.setData(index,Qt::AlignCenter,Qt::TextAlignmentRole);
            model.setData(index, QVariant(row));
        }
        for (int column=1;column<2;column++) {
            QModelIndex index = model.index(row, column, QModelIndex());
            model.setData(index,Qt::AlignCenter,Qt::TextAlignmentRole);
            model.setData(index, QVariant("*"));
        }
        for (int column=7;column<8;column++) {
            QModelIndex index = model.index(row, column, QModelIndex());
            model.setData(index,Qt::AlignCenter,Qt::TextAlignmentRole);
            model.setData(index, QVariant());
        }


    }

    tableView.setWindowTitle(QObject::tr("MoeJoeTP"));
    tableView.resize(1000,600);
    tableView.show();
    return app.exec();
}

#ifndef MYTABLE_H
#define MYTABLE_H

#include<QAbstractTableModel>
class MyModel : public QAbstractTableModel {
    Q_OBJECT
   public:
    //different function declarations to set data,column headers and tablesize
    MyModel(QObject *parent);
    int rowCount(const QModelIndex &parent=QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent=QModelIndex()) const override ;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // MYTABLE_H

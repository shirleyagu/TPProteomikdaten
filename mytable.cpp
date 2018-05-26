#include "mytable.h"
#include <QCheckBox>
#include <QStandardItem>

MyModel::MyModel(QObject *parent):QAbstractTableModel(parent){}


int MyModel::rowCount(const QModelIndex &/*parent*/) const{return 5;} //set rowsize of the table
int MyModel::columnCount(const QModelIndex &/*parent*/) const{return 13;} //set columnsize of the talbe

QVariant MyModel::data(const QModelIndex &index, int role)const{ //to add data inside the table
    int row = index.row();
    int col = index.column();

    if(col == 12 && role == Qt::CheckStateRole){

        return Qt::CheckStateRole;
        }
    return QVariant();
}

//set headers for each column of the table
QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role== Qt::DisplayRole){
        if(orientation==Qt::Horizontal){
            switch(section){
            case 0: return QString("#");
            case 1: return QString("...");
            case 2: return QString("PI");
            case 3: return QString("Accession");
            case 4: return QString("Description");
            case 5: return QString("Chr");
            case 6: return QString("Coverage");
            case 7: return QString("#Peptides");
            case 8: return QString("#Spectra");
            case 9: return QString("MS2 Quant");
            case 10: return QString("MW");
            case 11: return QString("Confidence");
            case 12: return QString("Check");

            }
        }
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if(role == Qt::CheckStateRole)
    {
        if ((Qt::CheckState)value.toInt() == Qt::Checked)
                {
                    //user has checked item
                    return true;
                }
                else
                {
                    //user has unchecked item
                    return true;
                }
    }

    return false;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    if(index.column() == 12){
        Qt::ItemFlags flags = QAbstractItemModel::flags(index);
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    }


}


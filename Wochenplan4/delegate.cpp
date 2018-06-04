#include "delegate.h"

#include <QCheckBox>

CheckBoxDelegate::CheckBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QCheckBox *editor = new QCheckBox(parent);
    //editor->setFrame(false);
   // editor->setMinimum(0);
   // editor->setMaximum(100);
    editor->setCheckState(Qt::Unchecked);

    return editor;
}

void CheckBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    bool tristate = index.model()->data(index, Qt::EditRole).toBool();

    QCheckBox *CheckBox = static_cast<QCheckBox*>(editor);
    CheckBox->setCheckState(Qt::CheckState());
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QCheckBox *CheckBox = static_cast<QCheckBox*>(editor);
    //CheckBox->interpretText();
    bool tristate = CheckBox->checkState();

    model->setData(index, tristate, Qt::CheckStateRole);
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

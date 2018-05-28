#include <QtWidgets>
#include <QTableView>

#include "delegate.h"
#include "editor.h"
#include "rating.h"

//painter for the bar
void BarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (index.data().canConvert<BarRating>()) {
        BarRating barRating = qvariant_cast<BarRating>(index.data());

        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());

        barRating.paint(painter, option.rect, option.palette,
                         BarRating::ReadOnly);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

//size
QSize BarDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.data().canConvert<BarRating>()) {
        BarRating barRating = qvariant_cast<BarRating>(index.data());
        return barRating.sizeHint();
    } else {
        return QStyledItemDelegate::sizeHint(option, index);
    }
}

QWidget *BarDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const

{
    if (index.data().canConvert<BarRating>()) {
        BarEditor *editor = new BarEditor(parent);
        connect(editor, &BarEditor::editingFinished,
                this, &BarDelegate::commitAndCloseEditor);
        return editor;
    } else {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}

void BarDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    if (index.data().canConvert<BarRating>()) {
        BarRating barRating = qvariant_cast<BarRating>(index.data());
       BarEditor *barEditor = qobject_cast<BarEditor *>(editor);
        barEditor->setBarRating(barRating);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

//set the Model
void BarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    if (index.data().canConvert<BarRating>()) {
        BarEditor *barEditor = qobject_cast<BarEditor *>(editor);
        model->setData(index, QVariant::fromValue(barEditor->barRating()));
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void BarDelegate::commitAndCloseEditor()
{
    BarEditor *editor = qobject_cast<BarEditor *>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}

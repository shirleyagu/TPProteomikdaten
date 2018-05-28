#include <QtWidgets>

#include "editor.h"
#include "rating.h"

//set the valuechange per mouse click
BarEditor::BarEditor(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
}

//size set
QSize BarEditor::sizeHint() const
{
    return myBarRating.sizeHint();
}

//create the animated bar painting
void BarEditor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    myBarRating.paint(&painter, rect(), this->palette(),
                       BarRating::Editable);
}

//Way to change the bar value with the mouse
void BarEditor::mouseMoveEvent(QMouseEvent *event)
{
    int bar = BarPosition(event->x());

    if (bar != myBarRating.barCount() && bar != -1) {
        myBarRating.setBarCount(bar);
        update();
    }
}

// set whats happening if the mouse click is released
void BarEditor::mouseReleaseEvent(QMouseEvent * )
{
    emit editingFinished();
}

//Editing the position of the bar
int BarEditor::BarPosition(int x)
{
    int bar = (x / (myBarRating.sizeHint().width()
                     / myBarRating.maxBarCount())) + 1;
    if (bar <= 0 || bar > myBarRating.maxBarCount())
        return -1;

    return bar;
}

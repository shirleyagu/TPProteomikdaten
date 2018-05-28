#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

#include "rating.h"

class BarEditor : public QWidget
{
    Q_OBJECT

public:
    BarEditor(QWidget *parent = 0);

    QSize sizeHint() const override;
    void setBarRating(const BarRating &barRating) {
        myBarRating = barRating;
    }
    BarRating barRating() { return myBarRating; }

signals:
    void editingFinished();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int BarPosition(int x);

    BarRating myBarRating;
};

#endif // EDITOR_H

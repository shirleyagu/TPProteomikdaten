#include <QtWidgets>
#include<QPainter>
#include <cmath>

#include "rating.h"

const int PaintingScaleFactor = 20;


//Draw the rating with the bar
BarRating::BarRating(int BarMin, int BarMax)
{
    myBarCount = BarMin;
    myMaxBarCount = BarMax;

    //starPolygon << QPointF(1.0, 0.5);
    for (int i = 0; i < 100; ++i){
        //starPolygon << QPointF(0.5 + 0.5 * std::cos(0.8 * i * 3.14),
          //                     0.5 + 0.5 * std::sin(0.8 * i * 3.14));

    //diamondPolygon << QPointF(0.4, 0.5) << QPointF(0.5, 0.4)
      //             << QPointF(0.6, 0.5) << QPointF(0.5, 0.6)
        //           << QPointF(0.4, 0.5);

    QRectF BarShape(0.1,0.1,i*0.01,1);}

}

//set Size
QSize BarRating::sizeHint() const
{
    return PaintingScaleFactor * QSize(myMaxBarCount, 1);
}

//paint the graphics and color it
void BarRating::paint(QPainter *painter, const QRect &rect,
                       const QPalette &palette, EditMode mode) const
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::NoPen);

    if (mode == Editable) {
        painter->setBrush(Qt::green);
    } else {
        painter->setBrush(palette.foreground());
    }

    int yOffset = (rect.height() - PaintingScaleFactor) / 2;
    painter->translate(rect.x(), rect.y() + yOffset);
    painter->scale(PaintingScaleFactor, PaintingScaleFactor);

    for (int i = 0; i < myMaxBarCount; ++i) {
        if (i < myBarCount) {
            painter->drawRect(BarShape);
        }
        painter->translate(1.0, 0.0);
    }

    painter->restore();
}

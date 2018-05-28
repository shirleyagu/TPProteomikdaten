#ifndef RATING_H
#define RATING_H

#include <QMetaType>
#include <QPointF>
#include <QVector>

class BarRating
{
public:
    enum EditMode { Editable, ReadOnly };

    explicit BarRating(int BarMin = 0, int BarMax = 100);

    void paint(QPainter *painter, const QRect &rect,
               const QPalette &palette, EditMode mode) const;
    QSize sizeHint() const;
    int barCount() const { return myBarCount; }
    int maxBarCount() const { return myMaxBarCount; }
    void setBarCount(int barCount) { myBarCount = barCount; }
    void setMaxBarCount(int maxBarCount) { myMaxBarCount = maxBarCount; }

private:
    //QPolygonF starPolygon;
    //QPolygonF diamondPolygon;
    QRect BarShape;
    int myBarCount;
    int myMaxBarCount;
};

Q_DECLARE_METATYPE(BarRating)


#endif // RATING_H

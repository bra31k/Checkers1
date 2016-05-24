#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <QGraphicsItem>

class Cell;
class QGraphicsSimpleTextItem;


class Checker : public QGraphicsItem
{
public:
    Checker(Cell *cell);

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    enum State {
        StateBlack,
        StateWhite
    };
    bool Color1 { true };
    void setState(State stat);
    State state() {return m_state;}
    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Cell *m_cell;
    State m_state;
};

#endif // CHECKER_HPP

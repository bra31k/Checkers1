#ifndef CELLITEM_HPP
#define CELLITEM_HPP

#include <QGraphicsItem>

class Cell;
class QGraphicsSimpleTextItem;

class CellItem : public QGraphicsItem
{
public:
    CellItem(Cell *cell);

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    enum State {
        StateNothing,
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
    QGraphicsSimpleTextItem *m_text;
    State m_state;
};

#endif // CELLITEM_HPP

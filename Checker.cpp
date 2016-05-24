#include "Checker.hpp"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSimpleTextItem>
#include <QPainter>
#include <QGraphicsEllipseItem>
#include "Cell.hpp"

const int cellSize = 32;

Checker::Checker(Cell *cell) :
    QGraphicsItem()
{
    m_cell = cell;

//    QFont f = m_text->font();
//    f.setPixelSize(cellSize - 4);
//    m_text->setFont(f);

    setPos(m_cell->x() * cellSize, m_cell->y() * cellSize);
}

QRectF Checker::boundingRect() const
{
    return QRectF(0, 0, cellSize, cellSize);
}

void Checker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   switch (m_state) {
   case StateBlack:
       painter->drawEllipse(0,0,cellSize,cellSize);
       break;
   case StateWhite:
       painter->drawEllipse(0,0,cellSize,cellSize);
       break;
   }
}
void Checker::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
}

void Checker::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

    }

    update();
}

void Checker::setState(State stat)
{
    if (m_state == stat)
    {
        return;
    }
    m_state=stat;

    update();
}

#include "CellItem.hpp"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSimpleTextItem>
#include <QPainter>

#include "Cell.hpp"

const int cellSize = 32;

CellItem::CellItem(Cell *cell) :
    QGraphicsItem()
{
    m_cell = cell;
    m_text = new QGraphicsSimpleTextItem(this);

    QFont f = m_text->font();
    f.setPixelSize(cellSize - 4);
    m_text->setFont(f);

    setPos(m_cell->x() * cellSize, m_cell->y() * cellSize);
}

QRectF CellItem::boundingRect() const
{
    return QRectF(0, 0, cellSize, cellSize);
}

void CellItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    static const int border = 4;


    if (Color1) {
        painter->drawRect(0, 0, cellSize, cellSize);
        Color1 = false;
    } else {
        painter->drawRect(0, 0, cellSize, cellSize);
//        painter->fillRect(border, border, cellSize - border * 2, cellSize - border * 2, Qt::lightGray);
        Color1 = true;
    }
    switch (m_state) {
    case StateBlack:
        painter->drawEllipse(0,0,cellSize,cellSize);
        break;
    case StateWhite:
        painter->drawEllipse(0,0,cellSize,cellSize);
        break;
    case StateNothing:
        painter->drawRect(0, 0, cellSize, cellSize);
    }

//    if (m_cell->x() and m_cell->y()){
//       painter->drawEllipse(0,0,cellSize,cellSize);
//    }
//    painter->drawEllipse(0,0,cellSize,cellSize);


//    if (m_cell->isOpen()) {
//        if (m_cell->haveMine()) {
//            painter->fillRect(border, border, cellSize - border * 2, cellSize - border * 2, Qt::red);
//            m_text->setText("+");
//        } else if (m_cell->minesAround() != 0) {
//            m_text->setText(QString::number(m_cell->minesAround()));
//        }
//    } else {
//        painter->fillRect(border, border, cellSize - border * 2, cellSize - border * 2, Qt::lightGray);
//        m_text->setText("");
//    }
    m_text->setPos((cellSize - m_text->boundingRect().width()) / 2, (cellSize - m_text->boundingRect().height()) / 2);
}
void CellItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
}

void CellItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_cell->open();
    }

    update();
}

void CellItem::setState(State stat)
{
    if (m_state == stat)
    {
        return;
    }
    m_state=stat;

    update();
}

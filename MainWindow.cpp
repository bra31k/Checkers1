#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include "Field.hpp"
#include "CellItem.hpp"
#include <QGLWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <Checker.hpp>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();
    m_field = new Field();
    m_field->setSize(10, 10);
    m_field->setNumberOfMines(0);

    QGLFormat f = QGLFormat::defaultFormat();
    f.setSampleBuffers(true);
    f.setSamples(4);

    ui->graphicsView->setViewport(new QGLWidget(f));

    ui->graphicsView->setScene(m_scene);

    for (int y = 0; y < m_field->height(); ++y) {
        for (int x = 0; x < m_field->width(); ++x) {
            m_scene->addItem(new CellItem(m_field->cellAt(x, y)));
            //            if (m_field->cellAt(x,y)%2 == 0) {
            //                   CellItem(m_field->cellAt(x,y))->setState(CellItem::StateNothing);

        }
    }

    for (int y = 0; y < m_field->height(); ++y) {
        if (y != 4 and y !=5 ){
            if (y%2){
                for (int x = 0; x < m_field->width(); ++x) {
                    if (x%2 == 0){
                        m_scene->addItem(new Checker(m_field->cellAt(x, y)));
//                        Checker->setState(Checker::StateBlack);
                    }
                }
            } else {
                for (int x = 0; x < m_field->width(); ++x) {
                    if (x%2) {
                        m_scene->addItem(new Checker(m_field->cellAt(x, y)));
//                        Checker.setState(Checker::StateWhite);
                    }
                }
            }
        }
    }
//        if (y > 0){
//        if (y%2){
//            for (int x = 0; x < m_field->width(); ++x) {
//                if (x%2) {
//                    m_scene->addItem(new Checker(m_field->cellAt(x, y)));
//                }
//            }
//        }

//        }
//        else {
//            for (int x = 0; x < m_field->width(); ++x) {
//                if (y > 0){
//                if (x%y == 0) {
//                    m_scene->addItem(new Checker(m_field->cellAt(x, y)));
//                }
//                }
//            }

//        }
//    }
        newGame();
        m_field->generate(x(),y());
    }

void MainWindow::newGame()
{
    m_field->prepare();
    m_scene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QTimer::singleShot(0, this, SLOT(updateSceneScale()));
}

void MainWindow::updateSceneScale()
{
    ui->graphicsView->fitInView(m_scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::on_actionNew_game_triggered()
{
    newGame();
}

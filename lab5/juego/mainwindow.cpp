#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::mover()
{

}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(i->key() == Qt::Key_D){
        heroe->setX(heroe->x()+16);
        if(colisionPared()){
            heroe->setX(heroe->x()-16);
        }
    }
    else if(i->key() == Qt::Key_A){
        heroe->setX(heroe->x()-16);
        if(colisionPared()){
            heroe->setX(heroe->x()+16);
        }
    }
    else if(i->key() == Qt::Key_S){
        heroe->setY(heroe->y()+16);
        if(colisionPared()){
            heroe->setY(heroe->y()-16);
        }
    }
    else if(i->key() == Qt::Key_W){
        heroe->setY(heroe->y()-16);
        if(colisionPared()){
            heroe->setY(heroe->y()+16);
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    time = new QTimer;
    connect(time, SIGNAL(timeout()), this, SLOT(mover()));
    escena = new QGraphicsScene;
    //hago el heroe
    heroe = new Objetos(":/Image/Bomberman.png");
    heroe->setPos(16,16);
    //hago las paredes
    for (int i=0, numFila=0, valorARestar=0;i<415;i++) {
            pared[i] = new Objetos(":/Image/pared.png");
            if((i+1)%32==0){
                numFila=numFila+16;
                valorARestar+=32;
            }
            if(i<31||i>=384||i-valorARestar==0||(i-valorARestar)*16>=480){
                pared[i]->setPos((i-valorARestar)*16,numFila);
            }
            if((numFila/16)%2==0){
                if((i-valorARestar)%2==0){
                    pared[i]->setPos((i-valorARestar)*16,numFila);
                }
            }
            escena->addItem(pared[i]);
    }

    escena->setSceneRect(0,0,ui->graphicsView->width()-2, ui->graphicsView->height()-2);
    escena->addItem(heroe);

    //escena->removeItem(heroe);

    ui->graphicsView->setScene(escena);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete heroe;
    delete time;
    delete * pared;
}

bool MainWindow::colisionPared()
{
    bool hayColisionPared=false;
    for (int i=0;i<415;i++){
        if(heroe->collidesWithItem(pared[i])){
            hayColisionPared=true;
        }
    }
    return hayColisionPared;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"


/*Funcion mover enemigos
-los mueve de forma aleatoria
-verifica las colisiones con paredesfuertes, paredesdebiles y bombas
-verifica si hay contacto con el heroe*/
void MainWindow::moverEnemigos()
{
    if(!finDelJuego){

        for(int i=0;i<totalEnemigos1;i++){
            int num =(rand()%4+1);
            switch (num) {
            case 1:{
                enemigos1[i]->setX(enemigos1[i]->x()+16);
                if(colisionParedEnemigo1(i)){
                    enemigos1[i]->setX(enemigos1[i]->x()-16);
                }
                if(danoEnemigoAlHeroe()){
                    danoAlHeroe();
                }
                break;
            }
            case 2:{
                enemigos1[i]->setX(enemigos1[i]->x()-16);
                if(colisionParedEnemigo1(i)){
                    enemigos1[i]->setX(enemigos1[i]->x()+16);
                }
                if(danoEnemigoAlHeroe()){
                    danoAlHeroe();
                }
                break;
            }
            case 3:{
                enemigos1[i]->setY(enemigos1[i]->y()+16);
                if(colisionParedEnemigo1(i)){
                    enemigos1[i]->setY(enemigos1[i]->y()-16);
                }
                if(danoEnemigoAlHeroe()){
                    danoAlHeroe();
                }
                break;
            }
            case 4:{
                enemigos1[i]->setY(enemigos1[i]->y()-16);
                if(colisionParedEnemigo1(i)){
                    enemigos1[i]->setY(enemigos1[i]->y()+16);
                }
                if(danoEnemigoAlHeroe()){
                    danoAlHeroe();
                }
                break;
            }
            }
        }
    }
}


/*Funcion reconocer teclas
-nos permite mover al heroe
-verifica las colisiones con paredesfuertes, paredesdebiles
-verifica si hay contacto del heroe con un enemigo o con el fuego*/
void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(!finDelJuego){

        if(i->key() == Qt::Key_D){
            verificarDanoAlHeroe();
            heroe->setX(heroe->x()+16);
            verificarDanoAlHeroe();
            if(colisionPared()){
                heroe->setX(heroe->x()-16);
            }
            encuentroLlave();
            encuentroPuertaAbierta();
        }
        else if(i->key() == Qt::Key_A){
            verificarDanoAlHeroe();
            heroe->setX(heroe->x()-16);
            verificarDanoAlHeroe();
            if(colisionPared()){
                heroe->setX(heroe->x()+16);
            }
            encuentroLlave();
            encuentroPuertaAbierta();
        }
        else if(i->key() == Qt::Key_S){
            verificarDanoAlHeroe();
            heroe->setY(heroe->y()+16);
            verificarDanoAlHeroe();
            if(colisionPared()){
                heroe->setY(heroe->y()-16);
            }
            encuentroLlave();
            encuentroPuertaAbierta();
        }
        else if(i->key() == Qt::Key_W){
            verificarDanoAlHeroe();
            heroe->setY(heroe->y()-16);
            verificarDanoAlHeroe();
            if(colisionPared()){
                heroe->setY(heroe->y()+16);
            }
            encuentroLlave();
            encuentroPuertaAbierta();
        }
        else if(i->key() == Qt::Key_V){
            if(bombaDisponible){
                bombaDisponible=false;
                bomba = new Objetos(":/Image/bomba.png");
                bomba->setPos(heroe->x(),heroe->y());
                escena->addItem(bomba);
                tiempoBomba->start(1000);
            }
        }
    }
}

void MainWindow::mostrarLlamas()
{
    for(int i=0;i<5;i++){
        fuegoBomba[i] = new Objetos(":/Image/fuego1.png",16,16);
        if(i==0){
            fuegoBomba[i]->setPos(bomba->x(),bomba->y());
            if(!colisionFuegoPared(i)){
                escena->removeItem(paredDebil[colisionFuegoParedDebil(i)]);
                paredDebil[colisionFuegoParedDebil(i)]->traspasable=true;
                escena->addItem(fuegoBomba[i]);
                fuegoBomba[i]->haceDano=true;

            }
        }
        else if(i==1){
            fuegoBomba[i]->setPos(bomba->x()-16,bomba->y());
            if(!colisionFuegoPared(i)){
                escena->removeItem(paredDebil[colisionFuegoParedDebil(i)]);
                paredDebil[colisionFuegoParedDebil(i)]->traspasable=true;
                escena->addItem(fuegoBomba[i]);
                fuegoBomba[i]->haceDano=true;

            }
        }
        else if(i==2){
            fuegoBomba[i]->setPos(bomba->x()+16,bomba->y());
            if(!colisionFuegoPared(i)){
                escena->removeItem(paredDebil[colisionFuegoParedDebil(i)]);
                paredDebil[colisionFuegoParedDebil(i)]->traspasable=true;
                escena->addItem(fuegoBomba[i]);
                fuegoBomba[i]->haceDano=true;

            }
        }
        else if(i==3){
            fuegoBomba[i]->setPos(bomba->x(),bomba->y()+16);
            if(!colisionFuegoPared(i)){
                escena->removeItem(paredDebil[colisionFuegoParedDebil(i)]);
                paredDebil[colisionFuegoParedDebil(i)]->traspasable=true;
                escena->addItem(fuegoBomba[i]);
                fuegoBomba[i]->haceDano=true;
            }
        }
        else{
            fuegoBomba[i]->setPos(bomba->x(),bomba->y()-16);
            if(!colisionFuegoPared(i)){
                escena->removeItem(paredDebil[colisionFuegoParedDebil(i)]);
                paredDebil[colisionFuegoParedDebil(i)]->traspasable=true;
                escena->addItem(fuegoBomba[i]);
                fuegoBomba[i]->haceDano=true;
            }
        }
    }
    escena->removeItem(bomba);
    tiempoBomba->stop();
    tiempoFuego->start(250);

    if(danoFuegoAlHeroe()){
        danoAlHeroe();
    }
    for(int i=0;i<totalEnemigos1;i++){
        if(colisionFuegoEnemigos1(i)){
            escena->removeItem(enemigos1[i]);
            enemigos1[i]->haceDano=false;
            if(enemigos1[i]->daPuntos){
                puntaje+=50;//por cada enemigo, 50 puntos
                actualizarPuntaje();
                enemigos1[i]->daPuntos=false;
            }
        }
    }


}

void MainWindow::eliminarLlamas()
{
    for(int i=0;i<5;i++){
        escena->removeItem(fuegoBomba[i]);
        fuegoBomba[i]->haceDano=false;
    }
    if(danoFuegoAlHeroe()){
        danoAlHeroe();
    }
    for(int i=0;i<totalEnemigos1;i++){
        if(colisionFuegoEnemigos1(i)){
            escena->removeItem(enemigos1[i]);
            enemigos1[i]->haceDano=false;
            if(enemigos1[i]->daPuntos){
                puntaje+=50;//por cada enemigo, 50 puntos
                actualizarPuntaje();
                enemigos1[i]->daPuntos=false;
            }
        }
    }
    tiempoFuego->stop();
    bombaDisponible=true;

}

void MainWindow::actualizarTiempo()
{
    segundos++;
    ui->lcdTiempo->display(segundos);
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //seteo los tiempos
    tiempoLcd = new QTimer;
    connect(tiempoLcd, SIGNAL(timeout()), this, SLOT(actualizarTiempo()));
    tiempo = new QTimer;
    connect(tiempo, SIGNAL(timeout()), this, SLOT(moverEnemigos()));
    tiempoBomba = new QTimer;
    connect(tiempoBomba, SIGNAL(timeout()),this, SLOT(mostrarLlamas()));
    tiempoFuego = new QTimer;
    connect(tiempoFuego, SIGNAL(timeout()),this, SLOT(eliminarLlamas()));


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,ui->graphicsView->width()-2, ui->graphicsView->height()-2);
    ui->graphicsView->setScene(escena);



    mostrarMenu();

}

//deletes
MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete heroe;
    delete tiempo;
    delete * pared;
    delete * paredDebil;
    delete bomba;
    delete * enemigos1;
    delete * fuegoBomba;
    delete llave;
    delete puertaAbierta;
    delete puertaCerrada;
    delete gameOver;
    delete youWin;
    delete menu;
    delete controles;
}

//funciones
bool MainWindow::colisionPared()
{
    bool hayColisionPared=false;
    for (int i=0;i<415;i++){
        if( (heroe->collidesWithItem(pared[i]) || heroe->collidesWithItem(paredDebil[i])) && !paredDebil[i]->traspasable){
            hayColisionPared=true;
        }
    }
    return hayColisionPared;
}

bool MainWindow::colisionParedEnemigo1(int numEnemigo)
{
    bool hayColisionPared=false;
    for (int i=0;i<415;i++){
        if((enemigos1[numEnemigo]->collidesWithItem(bomba) || enemigos1[numEnemigo]->collidesWithItem(pared[i]) || enemigos1[numEnemigo]->collidesWithItem(paredDebil[i])) && !paredDebil[i]->traspasable){
            hayColisionPared=true;
        }
    }
    return hayColisionPared;
}

bool MainWindow::colisionFuegoPared(int numFuego)
{
    bool hayColisionPared=false;
    for (int i=0;i<415;i++){
        if(fuegoBomba[numFuego]->collidesWithItem(pared[i])){
            hayColisionPared=true;
        }
    }
    return hayColisionPared;
}

int MainWindow::colisionFuegoParedDebil(int numFuego)
{
    int paredAborrar=0;
    for (int i=0;i<415;i++){
        if(fuegoBomba[numFuego]->collidesWithItem(paredDebil[i])){
            paredAborrar = i;
        }
    }
    return paredAborrar;
}

bool MainWindow::colisionFuegoEnemigos1(int numEnemigo)
{
    bool hayColision=false;
    for (int i=0;i<5;i++){
        if(fuegoBomba[i]->collidesWithItem(enemigos1[numEnemigo])){
            hayColision=true;
        }
    }
    return hayColision;
}

bool MainWindow::danoEnemigoAlHeroe()
{
    bool hayDano=false;
    for(int i=0;i<totalEnemigos1;i++){
        if(heroe->collidesWithItem(enemigos1[i])&&enemigos1[i]->haceDano){
            hayDano=true;
        }
    }
    return hayDano;
}

bool MainWindow::danoFuegoAlHeroe()
{
    bool hayDano=false;
    for(int i=0;i<5;i++){
        if(heroe->collidesWithItem(fuegoBomba[i])&&fuegoBomba[i]->haceDano){
            hayDano=true;
        }
    }

    return hayDano;
}

void MainWindow::danoAlHeroe()
{
    heroe->setPos(16,16);
    if(vidas>0){
        vidas--;
    }
    ui->lcdVidas->display(vidas);
    if(vidas==0){
        gameOver = new Objetos(":/Image/lose.gif",465,177);
        gameOver->setPos(16,16);
        escena->addItem(gameOver);
        tiempoLcd->stop();
        tiempo->stop();
        finDelJuego=true;
        actualizarPuntaje();
        ui->botonNuevoJuego->show();
    }
}

void MainWindow::verificarDanoAlHeroe()
{
    if(danoEnemigoAlHeroe() || danoFuegoAlHeroe()){
        danoAlHeroe();
    }
}

void MainWindow::encuentroLlave()
{
    if(heroe->collidesWithItem(llave)){
        heroeTieneLlave=true;
        escena->removeItem(llave);
        escena->removeItem(puertaCerrada);
    }
}

void MainWindow::encuentroPuertaAbierta()
{
    if(heroe->collidesWithItem(puertaAbierta)&&heroeTieneLlave){
        youWin = new Objetos(":/Image/win.gif",465,177);
        youWin->setPos(16,16);
        escena->addItem(youWin);
        tiempoLcd->stop();
        tiempo->stop();
        finDelJuego=true;
        actualizarPuntaje();
        ui->botonNuevoJuego->show();


    }
}

void MainWindow::actualizarPuntaje()
{
    if(finDelJuego){
        if(vidas!=0){
            puntaje=puntaje + vidas*100;
            if(segundos<=120){
                puntaje=puntaje + (120-segundos)*5;//por cada seg ahorrados, 5 pts, osea, 10seg = 50pts.
            }
        }


    }
    ui->lcdPuntaje->display(puntaje);
}

void MainWindow::jugarDeNuevo()
{
    bombaDisponible=true;
    hayLlave=false;
    hayPuerta=false;
    heroeTieneLlave=false;
    finDelJuego=false;
    vidas=3;
    segundos=0;
    puntaje=0;



    //escena = new QGraphicsScene;
    fondo = new Objetos(":/Image/fondo.png",497,209);
    fondo->setPos(0,0);
    escena->addItem(fondo);

    //hago el heroe
    heroe = new Objetos(":/Image/Bomberman.png");
    heroe->setPos(16,16);

    //inicializo una bomba cualquiera
    bomba = new Objetos(":/Image/bomba.png");
    bomba->setPos(1000,1000);
    escena->addItem(bomba);
    tiempoBomba->start(1000);

    //hago las paredes fuertes y debiles y dos enemigos
    srand(time(NULL)); //inicializo la semilla aleatoria
    for (int i=0, numFila=0, valorARestar=0, numEnemigos1=0;i<415;i++) {
        pared[i] = new Objetos(":/Image/paredFuertepokemon.png",16,16);
        paredDebil[i] = new Objetos(":/Image/paredDebilpokemon.png",16,16);
        if((i+1)%32==0){
            numFila=numFila+16;
            valorARestar+=32;
        }
        if(i<31||i>=384||i-valorARestar==0||(i-valorARestar)*16>=480){
            pared[i]->setPos((i-valorARestar)*16,numFila);
        }
        else if( (numFila/16)%2==0 && (i-valorARestar)%2==0 ){
            pared[i]->setPos((i-valorARestar)*16,numFila);
            if(numEnemigos1!=totalEnemigos1){
                if((rand()%3+1)%2==0){
                    if((rand()%3+1)%2==0){
                        enemigos1[numEnemigos1] = new Objetos(":/Image/enemigo1.png");
                        enemigos1[numEnemigos1]->haceDano=true;
                        enemigos1[numEnemigos1]->setPos(pared[i]->x()+16,pared[i]->y());
                        escena->addItem(enemigos1[numEnemigos1]);
                        numEnemigos1++;
                    }
                }
            }
        }
        else{
            if((rand()%3+1)%2==0){
                //crear llave
                if(!hayLlave){
                    if((rand()%3+1)%2==0){
                        if((rand()%3+1)%2==0){
                            if((rand()%3+1)%2==0){
                                llave = new Objetos(":/Image/llave.png",12,12);
                                llave->setPos((i-valorARestar)*16+2,numFila+2);
                                escena->addItem(llave);//key
                                hayLlave=true;
                            }
                        }
                    }
                }
                else if(!hayPuerta){
                    if((rand()%3+1)%2==0){
                        if(hayLlave){
                            if((rand()%3+1)%2==0){
                                puertaAbierta = new Objetos(":/Image/puertaAbierta.png",12,12);
                                puertaCerrada = new Objetos(":/Image/puertaCerrada.png",12,12);
                                puertaAbierta->setPos((i-valorARestar)*16+2,numFila+2);
                                puertaCerrada->setPos((i-valorARestar)*16+2,numFila+2);
                                escena->addItem(puertaAbierta);//puerta
                                escena->addItem(puertaCerrada);//puerta
                                hayPuerta=true;
                            }
                        }
                    }
                }
                paredDebil[i]->setPos((i-valorARestar)*16,numFila);
            }
        }
        escena->addItem(pared[i]);

        if(paredDebil[i]->x()!=0 && !(paredDebil[i]->x()==32 && paredDebil[i]->y()==32)){
            escena->addItem(paredDebil[i]);
        }


    }
    if(!hayLlave || !hayPuerta || llave->collidesWithItem(puertaCerrada)){
        escena->invalidate();
        escena->update();
    }
    for(int i=33;i<36;i++){
        paredDebil[i]->traspasable=true;
        escena->removeItem(paredDebil[i]);
    }

    /*escena->addItem(llave);//key
    escena->addItem(puertaAbierta);//puerta
    escena->addItem(puertaCerrada);//puerta*/


    escena->addItem(heroe);

    ui->lcdVidas->display(vidas);
    ui->lcdPuntaje->display(puntaje);
    ui->lcdTiempo->display(segundos);

    tiempo->start(300);//tiempo mov enemigos
    tiempoLcd->start(1000);//tiempo de juego
    if(!hayLlave){
        jugarDeNuevo();
    }
}

void MainWindow::mostrarMenu()
{
    menu = new Objetos(":/Image/menu.png",497,209);
    menu->setPos(0,0);
    escena->addItem(menu);

    controles =new Objetos(":/Image/controles.png",210,100);
    controles->setPos(150,120);
    escena->addItem(controles);
    ui->lcdPuntaje->hide();
    ui->lcdTiempo->hide();
    ui->lcdVidas->hide();
    ui->labelPuntaje->hide();
    ui->labelTiempo->hide();
    ui->labelVidas->hide();
}

void MainWindow::on_botonNuevoJuego_clicked()
{
    jugarDeNuevo();

    ui->lcdPuntaje->show();
    ui->lcdTiempo->show();
    ui->lcdVidas->show();
    ui->labelPuntaje->show();
    ui->labelTiempo->show();
    ui->labelVidas->show();

    ui->botonNuevoJuego->setText("jugar de nuevo");

    ui->botonNuevoJuego->hide();
}

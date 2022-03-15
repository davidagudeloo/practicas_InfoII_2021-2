#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//incluyo todas las librerías en el .h
#include "QGraphicsScene"
#include "objetos.h"
#include <QKeyEvent>
#include <QTimer>

#include <cstdlib> //random
#include <time.h>  //para asegurar que se tenga un valor aleatorio



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void moverEnemigos();
    void mostrarLlamas();
    void eliminarLlamas();
    void actualizarTiempo();
public:
    void keyPressEvent(QKeyEvent * i);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_botonNuevoJuego_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * escena;
    Objetos * fondo;
    Objetos * heroe;
    Objetos * enemigos1[2];
    Objetos * pared[415];
    Objetos * llave;
    Objetos * puertaAbierta;
    Objetos * puertaCerrada;
    Objetos * paredDebil[415];
    Objetos * bomba;
    Objetos * fuegoBomba[5];
    Objetos * gameOver;
    Objetos * youWin;
    QTimer * tiempoLcd;
    QTimer * tiempo;
    QTimer * tiempoBomba;
    QTimer * tiempoFuego;
    bool bombaDisponible=true;
    bool hayLlave=false;
    bool hayPuerta=false;
    bool heroeTieneLlave=false;
    bool finDelJuego=false;
    int vidas=3;
    int segundos=0;
    int puntaje=0;
    int totalEnemigos1=3;



    bool colisionPared();
    bool colisionParedEnemigo1(int numEnemigo);
    bool colisionFuegoPared(int numFuego);
    int colisionFuegoParedDebil(int numFuego);
    bool colisionFuegoEnemigos1(int numEnemigo);
    bool danoEnemigoAlHeroe();
    bool danoFuegoAlHeroe();
    void danoAlHeroe();
    void verificarDanoAlHeroe();
    void encuentroLlave();
    void encuentroPuertaAbierta();
    void actualizarPuntaje();
    void jugarDeNuevo();
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//incluyo todas las librerías en el .h
#include "QGraphicsScene"
#include "objetos.h"
#include <QKeyEvent>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void mover();

public:
    void keyPressEvent(QKeyEvent * i);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * escena;
    Objetos * heroe;
    Objetos * pared[415];
    QTimer * time;

    bool colisionPared();
};
#endif // MAINWINDOW_H

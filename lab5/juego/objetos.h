#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>

#include <QGraphicsPixmapItem>
#include <QString>

class Objetos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bool traspasable=false;
    bool haceDano=false;
    bool daPuntos=true;
    Objetos(QString name);
    Objetos(QString name,int w, int h);
};

#endif // OBJETOS_H

#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>

#include <QGraphicsPixmapItem>
#include <QString>

class Objetos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Objetos(QString name);
};

#endif // OBJETOS_H

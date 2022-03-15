#include "objetos.h"

Objetos::Objetos(QString name)
{
    setPixmap(QPixmap(name));

}

Objetos::Objetos(QString name, int w, int h)
{
    setPixmap(QPixmap(name).scaled(w,h));
}

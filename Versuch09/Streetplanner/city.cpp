#include "city.h"

City::City() {}
City::City(QString name, int x, int y):
    name(name), xCoord(x), yCoord(y)
{}
void City::draw(QGraphicsScene &scene) const{
    scene.addEllipse (xCoord , yCoord , 4, 4, QPen (Qt::red ) , QBrush (Qt::red , Qt::SolidPattern ));


    QGraphicsTextItem* textName = new QGraphicsTextItem(name);


    textName->setPos(xCoord, yCoord);


    scene.addItem(textName);

}
QString City::getName() const{
    return name;
}
int City::getX() const{
    return xCoord;
}
int City::getY() const{
    return yCoord;
}

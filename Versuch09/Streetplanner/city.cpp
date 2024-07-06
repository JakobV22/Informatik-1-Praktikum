#include "city.h"

City::City() {}


City::City(QString name, int x, int y):
    name(name), xCoord(x), yCoord(y)
{}


/**
 * @brief adds City-object to the scene
 * @param scene reference to the active scene
 */
void City::draw(QGraphicsScene &scene) const{
    scene.addEllipse (xCoord , yCoord , 4, 4, QPen (Qt::red ) , QBrush (Qt::red , Qt::SolidPattern ));


    QGraphicsTextItem* textName = new QGraphicsTextItem(name);


    textName->setPos(xCoord, yCoord);


    scene.addItem(textName);


}

/**
 * @brief returns name of City-object
 * @return name
 */
QString City::getName() const{
    return name;
}

/**
 * @brief returns x-coordinate of City-object
 * @return x-coordinate
 */
int City::getX() const{
    return xCoord;
}
/**
 * @brief returns y-coordinate of City-object
 * @return y-coordinate
 */
int City::getY() const{
    return yCoord;
}

#include "street.h"

Street::Street(City* city1, City* city2):
    city1(city1), city2(city2)
{}


/**
 * @brief draw the street as a line between the 2 cities (attributes of Street-object)
 * @param scene scene attribute of main window
 */
void Street::draw(QGraphicsScene& scene)const{

    //get coordinatess of the cities, the street is connecting
    int x1 = getCity1()->getX();
    int y1 = getCity1()->getY();
    int x2 = getCity2()->getX();
    int y2 = getCity2()->getY();

    //add a line between those points
    scene.addLine(x1, y1, x2, y2);

}

/**
 * @brief get city1 attribute from a Street-object
 * @return pointer to city on one end (1)
 */
City* Street::getCity1() const{
    return city1;
}

/**
 * @brief get city12 attribute from a Street-object
 * @return pointer to city on other end (2)
 */
City* Street::getCity2() const{
    return city2;
}

/**
 * @brief draw the street as a thick red line between the 2 cities (attributes of Street-object)
 * @param scene scene attribute of main window
 */
void Street::drawRed(QGraphicsScene& scene) const{

    //get city coordinates
    int x1 = getCity1()->getX();
    int y1 = getCity1()->getY();
    int x2 = getCity2()->getX();
    int y2 = getCity2()->getY();

    //set pen wide and red
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(255,0,0));

    //add line
    scene.addLine(x1, y1, x2, y2,pen);
}

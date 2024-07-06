#ifndef STREET_H
#define STREET_H
#include "city.h"


/**
 * @brief The Street class contains 2 City-objects as attributes which the street connects. It contains methods to get these protected attributes and to draw a Street-object
 * as a line in different styles
 */
class Street
{
public:
    Street(City* city1, City* city2);
    void draw(QGraphicsScene& scene) const;
    City* getCity1() const;
    City* getCity2() const;
    void drawRed(QGraphicsScene& scene) const;
protected:
    City* city1;
    City* city2;
};

#endif // STREET_H

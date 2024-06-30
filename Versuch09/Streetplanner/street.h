#ifndef STREET_H
#define STREET_H
#include "city.h"

class Street
{
public:
    Street(City* city1, City* city2);
    void draw(QGraphicsScene& scene) const;
    City* getCity1() const;
    City* getCity2() const;
protected:
    City* city1;
    City* city2;
};

#endif // STREET_H

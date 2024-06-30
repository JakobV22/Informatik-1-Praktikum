#include "street.h"

Street::Street(City* city1, City* city2):
    city1(city1), city2(city2)
{}
void Street::draw(QGraphicsScene& scene)const{
    int x1 = getCity1()->getX();
    int y1 = getCity1()->getY();
    int x2 = getCity2()->getX();
    int y2 = getCity2()->getY();
    scene.addLine(x1, y1, x2, y2);

}
City* Street::getCity1() const{
    return city1;
}
City* Street::getCity2() const{
    return city2;
}

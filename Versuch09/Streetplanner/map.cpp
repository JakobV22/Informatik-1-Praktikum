#include "map.h"


Map::Map() {}
void Map::addCity(City* cityPtr){
    cityList.append(cityPtr);
    qDebug() << cityPtr->getName();
}
void Map::draw(QGraphicsScene& scene) const{
    for(int i = 0; i<cityList.size(); i++){
        cityList[i]->draw(scene);
    }
}

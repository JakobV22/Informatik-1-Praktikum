#include "map.h"
#include "city.h"
#include<cmath>

Map::Map() {}
void Map::addCity(City* cityPtr){
    cityList.append(cityPtr);

}
void Map::draw(QGraphicsScene& scene) const{
    for(int i = 0; i<cityList.size(); i++){
        cityList[i]->draw(scene);
    }
    for(int i = 0; i<streetList.size(); i++){
        streetList[i]->draw(scene);
    }
}
bool Map::addStreet(Street* streetPtr){

    City* streetCity1 = streetPtr->getCity1();
    City* streetCity2 = streetPtr->getCity2();

    if(cityList.contains(streetCity1) && cityList.contains(streetCity2)){
        streetList.append(streetPtr);
        qDebug() << streetCity1->getName()<< "und" << streetCity2->getName() << "in cityList entahlten";
        return true;
    }
    else return false;

}
void Map::debugCities() const{
    for(int i = 0; i<cityList.size(); i++){
        qDebug() << cityList[i]->getName();
}
}
City* Map::findCity(const QString cityName) const{
    for(int i = 0; i<cityList.size(); i++){
        if(cityList[i]->getName() == cityName){
            return cityList[i];
        }

}
    return nullptr;
}
QVector<Street*> Map::getStreetList(const City* city) const{
    QVector<Street*> cityStreetList;
    for(int i = 0; i<streetList.size(); i++){
        if(streetList[i]->getCity1() == city || streetList[i]->getCity2() == city){
            cityStreetList.append(streetList[i]);
        }
}
    return cityStreetList;
}
City* Map::getOppositeCity(const Street* street, const City* city) const{
    if(street->getCity1() == city){
        return street->getCity2();
    }
    else if (street->getCity2() == city){
        return street->getCity1();
    }
    else return nullptr;
}
double Map::getLength(const Street* street) const{
    double x1 = street->getCity1()->getX();
    double y1 = street->getCity1()->getY();
    double x2 = street->getCity2()->getX();
    double y2 = street->getCity2()->getY();

    double diffX = abs(x1-x2);
    double diffY = abs(y1-y2);
    double length = sqrt(pow(diffX,2) + pow(diffY,2));
    return length;
}

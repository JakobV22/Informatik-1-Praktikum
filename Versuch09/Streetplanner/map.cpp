#include "map.h"
#include "city.h"
#include<cmath>

Map::Map() {}


/**
 * @brief add City-object to city List, if no City-object with same name is already contained in list
 * @param cityPtr pointer to City-object thats supposed to be added
 */
void Map::addCity(City* cityPtr){

    //check if similar named city is already contained
    bool ok = true;
    for (int i=0; i< cityList.size(); i++){
        if(cityList[i]->getName() == cityPtr->getName()){
            ok = false;
        }
    }
    //if no such object is already in the list, add the new City-object to it
    if(ok) cityList.append(cityPtr);
    }


/**
 * @brief draw every City- and Street-objecet in map
 * @param scene scene attribute of main window
 */
void Map::draw(QGraphicsScene& scene) const{

    //draw all cities in city list
    for(int i = 0; i<cityList.size(); i++){
        cityList[i]->draw(scene);
    }

    //draw all streets in street list
    for(int i = 0; i<streetList.size(); i++){
        streetList[i]->draw(scene);
    }
}
/**
 * @brief add Street-object to street list if the cities the street-candidate connects both exist in city list
 * @param streetPtr pointer to Street-object thats supposed to be added
 * @return true if cities exist and as a result new Street was added, false otherwise
 */
bool Map::addStreet(Street* streetPtr){

    //get both cities, the new street should connect
    City* streetCity1 = streetPtr->getCity1();
    City* streetCity2 = streetPtr->getCity2();

    //if both City-objects are contained in city list, adding the new street is valid, add, return true
    if(cityList.contains(streetCity1) && cityList.contains(streetCity2)){
        streetList.append(streetPtr);
        qDebug() << streetCity1->getName()<< "und" << streetCity2->getName() << "in cityList entahlten";
        return true;
    }
    //
    else return false;

}

/**
 * @brief prints the contens of city list
 */
void Map::debugCities() const{
    for(int i = 0; i<cityList.size(); i++){
        qDebug() << cityList[i]->getName();
}
}


/**
 * @brief finds City-object in city list by name attribute of City-object
 * @param cityName QString name attribute used for searching
 * @return pointer to corresponding City-object if city list contains such an object. Returns nullptr if not
 */
City* Map::findCity(const QString cityName) const{
    for(int i = 0; i<cityList.size(); i++){
        if(cityList[i]->getName() == cityName){
            return cityList[i];
        }

}
    return nullptr;
}


/**
 * @brief searches for Streets connecting a certain city with other cities
 * @param city pointer to City-object in question
 * @return vector with pointers to every Street-object featuring the respective City-object
 */
QVector<Street*> Map::getStreetList(const City* city) const{
    QVector<Street*> cityStreetList;
    for(int i = 0; i<streetList.size(); i++){
        if(streetList[i]->getCity1() == city || streetList[i]->getCity2() == city){
            cityStreetList.append(streetList[i]);
        }
}
    return cityStreetList;
}
/**
 * @brief finds city on the other end of a certain street coming from a certain city
 * @param street pointer to Street-object in question
 * @param city pointer to City-object in question
 * @return pointer to the City-object on the other side of the street in question coming from the city in question
 */
City* Map::getOppositeCity(const Street* street, const City* city) const{

    //if param City-object is city1 in attributes of param Street-object: return attribute city2
    if(street->getCity1() == city){
        return street->getCity2();
    }
    // else if param City-object is city2 in attributes of param Street-object: return attribute city1
    else if (street->getCity2() == city){
        return street->getCity1();
    }
    //else: param Street and param City apparentely dont match, so no opposite city can be found: return nullptr
    else return nullptr;
}

/**
 * @brief calculates the length of a certain Street
 * @param street pointer to Street-object in question
 * @return double length of street
 */
double Map::getLength(const Street* street) const{

    //get positions of the cities the street is connecting
    double x1 = street->getCity1()->getX();
    double y1 = street->getCity1()->getY();
    double x2 = street->getCity2()->getX();
    double y2 = street->getCity2()->getY();

    //pythagoras
    double diffX = abs(x1-x2);
    double diffY = abs(y1-y2);
    double length = sqrt(pow(diffX,2) + pow(diffY,2));
    return length;
}

/**
 * @brief get city list attribute from map
 * @return QList city list
 */
QList<City*> Map::getCityList(){
    return cityList;
}

#ifndef MAP_H
#define MAP_H
#include "city.h"
#include "street.h"
#include "abstractmap.h"
#include <QList>
#include<QDebug>
#include<QMessageBox>
#include<QGraphicsView>
#include <QRandomGenerator>
#include <QGraphicsTextItem>


/**
 * @brief The Map class is used to store a city- and street-list containing every added Street- and City-object. It contains methods to add these objects, debug them, find specific
 * objects by attributes, drwa every object onto the scene and to get certain protected attributes of this class
 */
class Map : public AbstractMap
{
public:
    Map();
    void addCity(City* cityPtr);
    void draw(QGraphicsScene& scene) const;
    bool addStreet(Street* streetPtr);
    void debugCities() const;
    City* findCity(const QString cityName)const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    QList<City*> getCityList();
protected:
    QList<City*> cityList;
    QList<Street*> streetList;
};

#endif // MAP_H

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

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City* cityPtr);
    void draw(QGraphicsScene& scene) const;
protected:
    QList<City*> cityList;
};

#endif // MAP_H

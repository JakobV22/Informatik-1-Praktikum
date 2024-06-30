#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
class City
{
public:
    City();
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene) const;
    QString getName() const;
    int getX() const;
    int getY() const;
protected:
    QString name;
    int xCoord;
    int yCoord;
};

#endif // CITY_H

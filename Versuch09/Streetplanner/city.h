#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

/**
 * @brief The City class contains objects with x and y coordinates, a QString name and methods to get thos attributes
 * and to draw the object onto the scene as a name labled point with x and y coordinates
 */
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

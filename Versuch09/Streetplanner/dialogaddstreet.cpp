#include "dialogaddstreet.h"
#include "ui_dialogaddstreet.h"

DialogAddStreet::DialogAddStreet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddStreet)
{
    ui->setupUi(this);
}

DialogAddStreet::~DialogAddStreet()
{
    delete ui;
}

/**
 * @brief creates a new Street-object by connecting the two cities input in the 2 line edit input fields
 * @param map current map, to find the responding City-objects
 * @return Pointer to the newly created Street
 */
Street* DialogAddStreet::fetchStreet(Map& map) const{

    //getting the 2 names of the 2 cities the new Street should connect
    QString cityName1 = ui->lineEdit_street_city1->text();
    QString cityName2 = ui->lineEdit_street_city2->text();

    //finding the corresponding City-objects in the City-List of map
    City* city1 = map.findCity(cityName1);
    City* city2 = map.findCity(cityName2);

    //if one of the corresponding City-Objects doesnt exist (invalid name input) return nullptr
    if(city1 == nullptr || city2 == nullptr){
        return nullptr;
    }
    //if both cities exist create new Street connecting the 2 and return a pointer to it
    else{
    Street* newStreetPtr = new Street(city1, city2);
    return newStreetPtr;
    }
}

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
Street* DialogAddStreet::fetchStreet(Map& map) const{
    QString cityName1 = ui->lineEdit_street_city1->text();
    QString cityName2 = ui->lineEdit_street_city2->text();
    City* city1 = map.findCity(cityName1);
    City* city2 = map.findCity(cityName2);

    Street* newStreetPtr = new Street(city1, city2);
    return newStreetPtr;
}

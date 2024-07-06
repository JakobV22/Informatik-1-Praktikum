#include "dialogneuestadt.h"
#include "ui_dialogneuestadt.h"

DialogNeueStadt::DialogNeueStadt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNeueStadt)
{
    ui->setupUi(this);
}

DialogNeueStadt::~DialogNeueStadt()
{
    delete ui;
}

/**
 * @brief creates a new City-object with the coordinates put into the 2 line edit input fields and the name put into the 3rd line edit
 * @return Pointer to the newly created City
 */
City* DialogNeueStadt::fetchCity()
{
    //getting the inputs for name, xCoord and yCoord from the line edit fields
    int xCoord = ui->lineEdit_xCoord->text().toInt();
    int yCoord = ui->lineEdit_yCoord->text().toInt();
    QString name = ui->lineEdit_name_stadt->text();

    //creating new City-object
    City* newCityPtr = new City(name, xCoord, yCoord);


    qDebug() << name << xCoord << yCoord;
    return newCityPtr;
}


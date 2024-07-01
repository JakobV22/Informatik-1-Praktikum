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

City* DialogNeueStadt::fetchCity()
{
    int xCoord = ui->lineEdit_xCoord->text().toInt();
    int yCoord = ui->lineEdit_yCoord->text().toInt();
    QString name = ui->lineEdit_name_stadt->text();
    City* newCityPtr = new City(name, xCoord, yCoord);
    qDebug() << name << xCoord << yCoord;
    return newCityPtr;
}


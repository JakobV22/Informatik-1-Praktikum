#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogneuestadt.h"
#include "dijkstra.h"

#include "dialogaddstreet.h"
#include<QDebug>
#include<QMessageBox>
#include<QGraphicsView>
#include <QRandomGenerator>
#include "city.h"
#include <QGraphicsTextItem>
#include <QDialog>
bool test = true;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    MapIoNrw* mapIoNrwPtr = new MapIoNrw();
    mapIoPtr = mapIoNrwPtr;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    QMessageBox msgBox;
    QString eingabe = ui->lineEdit_teste_was->text();
    int x =  QRandomGenerator::global()->bounded(0, 100);
    int y =  QRandomGenerator::global()->bounded(0, 100);
    scene.addRect(x, y, 100, 50);
    bool ok;
    int potNumber = eingabe.toInt(&ok, 10);
    if(ok == true){
        QString eingabe1 = QString("Eingabe lautet: %1 (int)").arg(potNumber);
        msgBox.setText(eingabe1);
        msgBox.exec();
        test == false;
    }
    else{
    QString eingabe1 = QString("Eingabe lautet: %1").arg(eingabe);
        msgBox.setText(eingabe1);
        msgBox.exec();
        test == true;
    }


}

void MainWindow::on_actionExit_triggered()
{
    close();
}



void MainWindow::on_actionAbout_triggered()
{
    QString title = QString("Information");
    QString aboutText = QString("Es handelt sich um eine einfache Anwendung zu Testzwecken");
    QMessageBox msgBox;
    msgBox.about(this, title, aboutText );
}







void MainWindow::on_actionClear_Scene_triggered()
{

  scene.clear();


}


void MainWindow::on_pushButton_Test_Draw_City_clicked()
{
    City Bielefeld = City(QString("Bielefeld"), -50, -100);
    City Mannheim = City(QString("Mannheim"), 100, -100);



    Bielefeld.draw(scene);
    Mannheim.draw(scene);
    qDebug() << Mannheim.getName() << ": x: " << Mannheim.getX() << " y: " << Mannheim.getY() << "\n";
    qDebug() << Bielefeld.getName() << ": x: " << Bielefeld.getX() << " y: " << Bielefeld.getY() << "\n";
}


void MainWindow::on_pushButton_Test_Draw_Map_clicked()
{
    int x =  QRandomGenerator::global()->bounded(-100, 100);
    int y =  QRandomGenerator::global()->bounded(-100, 100);
    City* c1 = new City("city test", x, y);
    map.addCity(c1);

    map.draw(scene);
}


void MainWindow::on_pushButton_Test_Draw_Street_clicked()
{
    int x =  QRandomGenerator::global()->bounded(-100, 100);
    int y =  QRandomGenerator::global()->bounded(-100, 100);
    City* c1 = new City("cityStreet1", x, y);
    x =  QRandomGenerator::global()->bounded(-100, 100);
    y =  QRandomGenerator::global()->bounded(-100, 100);
    City* c2 = new City("cityStreet2", x, y);
    map.addCity(c1);
    map.addCity(c2);
    Street s1(c1, c2);
    map.draw(scene);
    s1.draw(scene);
    map.debugCities();
}


void MainWindow::on_pushButton_Test_Add_Street_clicked()
{
    int x =  QRandomGenerator::global()->bounded(-100, 100);
    int y =  QRandomGenerator::global()->bounded(-100, 100);
    City* c1 = new City("cityStreetT1", x, y);
    City* c3 = new City("cityStreetT3", y, x);
    x =  QRandomGenerator::global()->bounded(-100, 100);
    y =  QRandomGenerator::global()->bounded(-100, 100);
    City* c2 = new City("cityStreetT2", x, y);
    City* c4 = new City("cityStreetT4", y, x);
    x =  QRandomGenerator::global()->bounded(-100, 100);
    y =  QRandomGenerator::global()->bounded(-100, 100);
    City* c5 = new City("cityStreetT5", x, y);
    map.addCity(c1);
    map.addCity(c2);
    map.addCity(c5);
    Street* s1y = new Street(c1, c2);
    Street* s2n = new Street(c1, c3);
    Street* s3n = new Street(c1, c4);
    Street* s4n = new Street(c2, c3);
    Street* s5n = new Street(c2, c4);
    Street* s6n = new Street(c3, c4);
    Street* s7y = new Street(c1, c5);
    Street* s8y = new Street(c2, c5);
    qDebug() << map.addStreet(s1y);
    qDebug() << map.addStreet(s2n);
    qDebug() << map.addStreet(s3n);
    qDebug() << map.addStreet(s4n);
    qDebug() << map.addStreet(s5n);
    qDebug() << map.addStreet(s6n);
    qDebug() << map.addStreet(s7y);
    qDebug() << map.addStreet(s8y);

    map.draw(scene);
    qDebug () << (c1==c2) << "erwarte false";
    map.debugCities();
}



void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()){
        ui->pushButton_teste_was->hide();
        ui->pushButton_Test_Draw_City->hide();
        ui->pushButton_Test_Draw_Map->hide();
        ui->pushButton_Test_Draw_Street->hide();
        ui->pushButton_Test_Add_Street->hide();
        ui->pushButton_test_abstract_map->hide();
        ui->pushButton_test_dijkstra->hide();
    }
    else{
        ui->pushButton_teste_was->show();
        ui->pushButton_Test_Draw_City->show();
        ui->pushButton_Test_Draw_Map->show();
        ui->pushButton_Test_Draw_Street->show();
        ui->pushButton_Test_Add_Street->show();
        ui->pushButton_test_abstract_map->show();
        ui->pushButton_test_dijkstra->show();
    }
}


void MainWindow::on_pushButton_add_city_clicked()
{
    DialogNeueStadt dialog;
    int a = dialog.exec();
    qDebug() << a;
    if(a==1){
        City* dialogCityPtr = dialog.fetchCity();
        map.addCity(dialogCityPtr);
        map.draw(scene);
        updateComboBoxes();
    }


}


void MainWindow::on_pushButton_fill_map_clicked()
{
    mapIoPtr->fillMap(map);
    map.draw(scene);
    updateComboBoxes();
}

void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_test_abstract_map_clicked()
{
    testAbstractMap();
}


void MainWindow::on_pushButton_test_dijkstra_clicked()
{

    QVector<Street*> shortestPath = Dijkstra::search(map, "Düsseldorf", "Aachen");
    for (int i = 0; i < shortestPath.size(); i++){
        shortestPath[i]->drawRed(scene);
    }

}


void MainWindow::on_pushButton_dijkstra_shortest_path_clicked()
{
    // QString name1 = ui->lineEdit_dijkstra_city_1->text();
    // QString name2 = ui->lineEdit_dijkstra_city_2->text();
    QString name1 = ui->comboBox_dijkstra_city_1->currentText();
    QString name2 = ui->comboBox_dijkstra_city_2->currentText();
    QVector<Street*> shortestPath = Dijkstra::search(map, name1, name2);
    for (int i = 0; i < shortestPath.size(); i++){
        shortestPath[i]->drawRed(scene);
    }

}


void MainWindow::on_pushButton_add_street_clicked()
{
    DialogAddStreet dialog;
    int a = dialog.exec();
    qDebug() << a;
    if(a==1){
        Street* dialogStreetPtr = dialog.fetchStreet(map);
        map.addStreet(dialogStreetPtr);
        map.draw(scene);
        updateComboBoxes();
    }
}

void MainWindow::updateComboBoxes(){
    ui->comboBox_dijkstra_city_1->clear();
    ui->comboBox_dijkstra_city_2->clear();
    QList <City*> cityList = map.getCityList();
    for(int i =0; i< map.getCityList().size(); i++){
        ui->comboBox_dijkstra_city_1->addItem(cityList[i]->getName());
        ui->comboBox_dijkstra_city_2->addItem(cityList[i]->getName());
}
}

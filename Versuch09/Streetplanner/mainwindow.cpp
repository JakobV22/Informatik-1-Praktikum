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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //sets scene of graphic view using the scene attribute of main window
    ui->graphicsView->setScene(&scene);

    //creates new MapIoNrw object, initialises mapIoPtr attribute of main window with that object
    MapIoNrw* mapIoNrwPtr = new MapIoNrw();
    mapIoPtr = mapIoNrwPtr;

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief when test button clicked: - open message box showing the input of the test line edit (either string or int is fine)
 *
 */
void MainWindow::on_pushButton_teste_was_clicked()
{
    QMessageBox msgBox;

    //getting the input of the test line edit as a string
    QString eingabe = ui->lineEdit_teste_was->text();

    //checks if input is int, if so bool ok = true, int potNumber = the string converted to int
    bool ok;
    int potNumber = eingabe.toInt(&ok, 10);

   //if input was int/ ok ==true: print the input to the message box containing the hint "(int)"
    if(ok == true){
        QString eingabe1 = QString("Eingabe lautet: %1 (int)").arg(potNumber);
        msgBox.setText(eingabe1);
        msgBox.exec();   
    }

    //if input was string print that string to message box
    //
    else{
    QString eingabe1 = QString("Eingabe lautet: %1").arg(eingabe);
        msgBox.setText(eingabe1);
        msgBox.exec();

    }

    //randomly generate x and y coordinate of a 100 by 50 size rectangle and add it to the scene
    int x =  QRandomGenerator::global()->bounded(0, 100);
    int y =  QRandomGenerator::global()->bounded(0, 100);
    scene.addRect(x, y, 100, 50);



}
/**
 * @brief when Exit is triggered under File on menu bar: close main window
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}


/**
 * @brief when About is triggered under Info on menu bar: print basic information on message box
 */
void MainWindow::on_actionAbout_triggered()
{
    QString title = QString("Information");
    QString aboutText = QString("Es handelt sich um eine einfache Anwendung zu Testzwecken");
    QMessageBox msgBox;
    msgBox.about(this, title, aboutText );
}






/**
 * @brief when clear is triggered under scene in menu: clear the scene
 */

void MainWindow::on_actionClear_Scene_triggered()
{

  scene.clear();


}

/**
 * @brief when test draw city button clicked: generate two hard coded cities and draw them onto scene
 */
void MainWindow::on_pushButton_Test_Draw_City_clicked()
{
    City Bielefeld = City(QString("Bielefeld"), -50, -100);
    City Mannheim = City(QString("Mannheim"), 100, -100);



    Bielefeld.draw(scene);
    Mannheim.draw(scene);
    qDebug() << Mannheim.getName() << ": x: " << Mannheim.getX() << " y: " << Mannheim.getY() << "\n";
    qDebug() << Bielefeld.getName() << ": x: " << Bielefeld.getX() << " y: " << Bielefeld.getY() << "\n";
}

/**
 * @brief when test draw Map button clicked: create city with random coordinates, add it to map-Object and draw it onto scene. City name is generated by using x and y coordinates in
 * the name to avoid the new city not being added because of name collision
 */
void MainWindow::on_pushButton_Test_Draw_Map_clicked()
{
    int x =  QRandomGenerator::global()->bounded(-100, 100);
    int y =  QRandomGenerator::global()->bounded(-100, 100);
    QString xStr;
    QString yStr;
    xStr.setNum(x);
    yStr.setNum(y);
    QString cityTestName = "city test ";
    City* c1 = new City(cityTestName.append(xStr).append(yStr), x, y);
    map.addCity(c1);

    map.draw(scene);
}

/**
 * @brief when test draw Street button clicked: create 2 cities with random coordinates, add them to map-Object and draw them onto scene. Then create new Street between
 *  those cities, add it to map-Object and draw it onto scen. City names are generated by using x and y coordinates in
 * the name to avoid the new cities not being added because of name collision
 */

void MainWindow::on_pushButton_Test_Draw_Street_clicked()
{
    //randomly generate city1
    int x =  QRandomGenerator::global()->bounded(-100, 100);
    int y =  QRandomGenerator::global()->bounded(-100, 100);
    QString xStr;
    QString yStr;
    xStr.setNum(x);
    yStr.setNum(y);
    QString cityStreetName = "cityStreet1.";
    City* c1 = new City(cityStreetName.append(xStr).append(yStr), x, y);


    x =  QRandomGenerator::global()->bounded(-100, 100);
    y =  QRandomGenerator::global()->bounded(-100, 100);
    xStr.setNum(x);
    yStr.setNum(y);
    cityStreetName = "cityStreet2.";
    City* c2 = new City(cityStreetName.append(xStr).append(yStr), x, y);

    // add cities to map-object
    map.addCity(c1);
    map.addCity(c2);

    //create new Street connecting the cities, add it to map
    Street* s1 = new Street(c1, c2);
    map.addStreet(s1);
    //draw map
    map.draw(scene);


    //update city name in combo boxes and print full city list
    updateComboBoxes();
    map.debugCities();
}

/**
 * @brief when test add street button clicked:
 */
void MainWindow::on_pushButton_Test_Add_Street_clicked()
{
    // create 5 City-objects with random coordinates
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

    //only add 3 of those 5 City-objects to the map
    map.addCity(c1);
    map.addCity(c2);
    map.addCity(c5);

    //create 8 Street-objects connecting various combinations of the added and unadded cities
    Street* s1y = new Street(c1, c2);
    Street* s2n = new Street(c1, c3);
    Street* s3n = new Street(c1, c4);
    Street* s4n = new Street(c2, c3);
    Street* s5n = new Street(c2, c4);
    Street* s6n = new Street(c3, c4);
    Street* s7y = new Street(c1, c5);
    Street* s8y = new Street(c2, c5);

    //print the results of the attempts to add each of the new streets to the map
    //only 3 Streets should be added since not all cities are in the city list of map
    qDebug() << map.addStreet(s1y);
    qDebug() << map.addStreet(s2n);
    qDebug() << map.addStreet(s3n);
    qDebug() << map.addStreet(s4n);
    qDebug() << map.addStreet(s5n);
    qDebug() << map.addStreet(s6n);
    qDebug() << map.addStreet(s7y);
    qDebug() << map.addStreet(s8y);

    //draw new 3 cities and new 3 streets as part of the map
    map.draw(scene);

    //update city names in combo boxes and print full city list
    updateComboBoxes();
    map.debugCities();
}


/**
 * @brief if check box "hide Tests" clicked: hide or show every test button depending on wether check box was checked or unchecked
 */
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

/**
 * @brief when add city button pressed: create dialog window (see dialogneuestadt.cpp). If "ok" is pressed in dialog window: dialog function will return a pointer
 * to a new City object which will then be added to map. Map will be drawn. Else if "cancel" is pressed said steps will not happen
 */
void MainWindow::on_pushButton_add_city_clicked()
{
    //create and execute the new city dialog
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

/**
 * @brief when fill map button clicked: uses MapIo member function fillMap, implemented in daughter class MapIoNrw to fill map with hard coded content
 */
void MainWindow::on_pushButton_fill_map_clicked()
{
    mapIoPtr->fillMap(map);
    map.draw(scene);
    updateComboBoxes();
}
/**
 * @brief test function
 */
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

/**
 * @brief when test abstract map button clicked: run avriety of tests to check funtionalities and debug results
 */
void MainWindow::on_pushButton_test_abstract_map_clicked()
{
    testAbstractMap();
}

/**
 * @brief when test dijkstra button pressed: run preimplemented dijkstra algorithm, returning Street* vector of shortest path between Aachen and Düsseldorf. Draw shortest path in thick red
 */
void MainWindow::on_pushButton_test_dijkstra_clicked()
{
    //run dijkstra for Aachen and Düsseldorf
    QVector<Street*> shortestPath = Dijkstra::search(map, "Düsseldorf", "Aachen");

    //draw the shortest path
    for (int i = 0; i < shortestPath.size(); i++){
        shortestPath[i]->drawRed(scene);
    }

}

/**
 * @brief when sijkstra shortest path button clicked: find shortest path between 2 cities (input through 2 combo boxes in main window) using dijkstra algorithm and
 * draw the path onto the scene in thick red
 */
void MainWindow::on_pushButton_dijkstra_shortest_path_clicked()
{
    // QString name1 = ui->lineEdit_dijkstra_city_1->text();
    // QString name2 = ui->lineEdit_dijkstra_city_2->text();

    //get names of cities through combo boxes
    QString name1 = ui->comboBox_dijkstra_city_1->currentText();
    QString name2 = ui->comboBox_dijkstra_city_2->currentText();

    //run dijkstra
    QVector<Street*> shortestPath = Dijkstra::search(map, name1, name2);

    //draw path
    for (int i = 0; i < shortestPath.size(); i++){
        shortestPath[i]->drawRed(scene);
    }

}

/**
 * @brief when add street button clicked: open add street dialog. If "ok" is pressed in dialog, dialog Function will create new Street object using information
 * put into line edits of the dialog window and return a pointer to it.
 * If "cancel" was pressed instead the dialog function will not be executed
 */
void MainWindow::on_pushButton_add_street_clicked()
{
    //create new dialog, execute it
    DialogAddStreet dialog;
    int a = dialog.exec();
    qDebug() << a;

    //if dialog "ok" was pressed
    if(a==1){

        //receive pointer to newly created Street-object
        Street* dialogStreetPtr = dialog.fetchStreet(map);

        //add new Street to map, draw map
        map.addStreet(dialogStreetPtr);
        map.draw(scene);

    }
}

/**
 * @brief clears both main window combo boxes and reloads the elements by using the current city List of map
 */
void MainWindow::updateComboBoxes(){

    //clear combo boxes
    ui->comboBox_dijkstra_city_1->clear();
    ui->comboBox_dijkstra_city_2->clear();

    //add city name of each City-object in city list to the combo boxes
    QList <City*> cityList = map.getCityList();
    for(int i =0; i< cityList.size(); i++){
        ui->comboBox_dijkstra_city_1->addItem(cityList[i]->getName());
        ui->comboBox_dijkstra_city_2->addItem(cityList[i]->getName());
}
}

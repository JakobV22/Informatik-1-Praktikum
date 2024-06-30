#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>
#include<QMessageBox>
#include<QGraphicsView>
#include <QRandomGenerator>
#include "city.h"
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
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
    }
    else{
    QString eingabe1 = QString("Eingabe lautet: %1").arg(eingabe);
        msgBox.setText(eingabe1);
        msgBox.exec();
    }
   ;

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
    City c1("city test", x, y);
    map.addCity(&c1);
    map.draw(scene);
}


void MainWindow::on_pushButton_Test_Draw_Street_clicked()
{
    int x =  QRandomGenerator::global()->bounded(-100, 100);
    int y =  QRandomGenerator::global()->bounded(-100, 100);
    City c1("cityStreetT1", x, y);
    x =  QRandomGenerator::global()->bounded(-100, 100);
    y =  QRandomGenerator::global()->bounded(-100, 100);
    City c2("cityStreetT2", x, y);
    map.addCity(&c1);
    map.addCity(&c2);
    Street s1(&c1, &c2);
    map.draw(scene);
    s1.draw(scene);
}


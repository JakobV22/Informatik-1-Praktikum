#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene scene;
    void testAbstractMap();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionClear_Scene_triggered();

    void on_pushButton_Test_Draw_City_clicked();

    void on_pushButton_Test_Draw_Map_clicked();

    void on_pushButton_Test_Draw_Street_clicked();

    void on_pushButton_Test_Add_Street_clicked();

    void on_checkBox_clicked();

    void on_pushButton_add_city_clicked();

    void on_pushButton_fill_map_clicked();

    void on_pushButton_test_abstract_map_clicked();

private:
    Ui::MainWindow *ui;
    Map map;
    MapIo* mapIoPtr;
};
#endif // MAINWINDOW_H

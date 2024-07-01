/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionClear_Scene;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Test_Add_Street;
    QCheckBox *checkBox;
    QPushButton *pushButton_Test_Draw_City;
    QSpacerItem *verticalSpacer;
    QLabel *label_eingabe;
    QPushButton *pushButton_test_dijkstra;
    QPushButton *pushButton_teste_was;
    QPushButton *pushButton_Test_Draw_Street;
    QLineEdit *lineEdit_teste_was;
    QPushButton *pushButton_add_city;
    QPushButton *pushButton_fill_map;
    QPushButton *pushButton_test_abstract_map;
    QPushButton *pushButton_Test_Draw_Map;
    QPushButton *pushButton_add_street;
    QComboBox *comboBox_dijkstra_city_1;
    QPushButton *pushButton_dijkstra_shortest_path;
    QComboBox *comboBox_dijkstra_city_2;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(454, 449);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName("actionClear_Scene");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(6);
        pushButton_Test_Add_Street = new QPushButton(centralwidget);
        pushButton_Test_Add_Street->setObjectName("pushButton_Test_Add_Street");

        gridLayout->addWidget(pushButton_Test_Add_Street, 6, 0, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 12, 0, 1, 1);

        pushButton_Test_Draw_City = new QPushButton(centralwidget);
        pushButton_Test_Draw_City->setObjectName("pushButton_Test_Draw_City");

        gridLayout->addWidget(pushButton_Test_Draw_City, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        label_eingabe = new QLabel(centralwidget);
        label_eingabe->setObjectName("label_eingabe");

        gridLayout->addWidget(label_eingabe, 0, 0, 1, 1);

        pushButton_test_dijkstra = new QPushButton(centralwidget);
        pushButton_test_dijkstra->setObjectName("pushButton_test_dijkstra");

        gridLayout->addWidget(pushButton_test_dijkstra, 10, 0, 1, 1);

        pushButton_teste_was = new QPushButton(centralwidget);
        pushButton_teste_was->setObjectName("pushButton_teste_was");

        gridLayout->addWidget(pushButton_teste_was, 2, 0, 1, 1);

        pushButton_Test_Draw_Street = new QPushButton(centralwidget);
        pushButton_Test_Draw_Street->setObjectName("pushButton_Test_Draw_Street");

        gridLayout->addWidget(pushButton_Test_Draw_Street, 5, 0, 1, 1);

        lineEdit_teste_was = new QLineEdit(centralwidget);
        lineEdit_teste_was->setObjectName("lineEdit_teste_was");
        lineEdit_teste_was->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_teste_was, 1, 0, 1, 1);

        pushButton_add_city = new QPushButton(centralwidget);
        pushButton_add_city->setObjectName("pushButton_add_city");

        gridLayout->addWidget(pushButton_add_city, 7, 0, 1, 1);

        pushButton_fill_map = new QPushButton(centralwidget);
        pushButton_fill_map->setObjectName("pushButton_fill_map");

        gridLayout->addWidget(pushButton_fill_map, 8, 0, 1, 1);

        pushButton_test_abstract_map = new QPushButton(centralwidget);
        pushButton_test_abstract_map->setObjectName("pushButton_test_abstract_map");

        gridLayout->addWidget(pushButton_test_abstract_map, 9, 0, 1, 1);

        pushButton_Test_Draw_Map = new QPushButton(centralwidget);
        pushButton_Test_Draw_Map->setObjectName("pushButton_Test_Draw_Map");

        gridLayout->addWidget(pushButton_Test_Draw_Map, 4, 0, 1, 1);

        pushButton_add_street = new QPushButton(centralwidget);
        pushButton_add_street->setObjectName("pushButton_add_street");

        gridLayout->addWidget(pushButton_add_street, 11, 0, 1, 1);

        comboBox_dijkstra_city_1 = new QComboBox(centralwidget);
        comboBox_dijkstra_city_1->setObjectName("comboBox_dijkstra_city_1");

        gridLayout->addWidget(comboBox_dijkstra_city_1, 2, 1, 1, 1);

        pushButton_dijkstra_shortest_path = new QPushButton(centralwidget);
        pushButton_dijkstra_shortest_path->setObjectName("pushButton_dijkstra_shortest_path");

        gridLayout->addWidget(pushButton_dijkstra_shortest_path, 3, 1, 1, 1);

        comboBox_dijkstra_city_2 = new QComboBox(centralwidget);
        comboBox_dijkstra_city_2->setObjectName("comboBox_dijkstra_city_2");

        gridLayout->addWidget(comboBox_dijkstra_city_2, 1, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 4, 1, 10, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 454, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuScene = new QMenu(menubar);
        menuScene->setObjectName("menuScene");
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(lineEdit_teste_was, pushButton_teste_was);
        QWidget::setTabOrder(pushButton_teste_was, pushButton_Test_Draw_City);
        QWidget::setTabOrder(pushButton_Test_Draw_City, pushButton_Test_Draw_Map);
        QWidget::setTabOrder(pushButton_Test_Draw_Map, pushButton_Test_Draw_Street);
        QWidget::setTabOrder(pushButton_Test_Draw_Street, pushButton_Test_Add_Street);
        QWidget::setTabOrder(pushButton_Test_Add_Street, pushButton_add_city);
        QWidget::setTabOrder(pushButton_add_city, pushButton_fill_map);
        QWidget::setTabOrder(pushButton_fill_map, pushButton_test_abstract_map);
        QWidget::setTabOrder(pushButton_test_abstract_map, pushButton_test_dijkstra);
        QWidget::setTabOrder(pushButton_test_dijkstra, checkBox);
        QWidget::setTabOrder(checkBox, graphicsView);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuScene->menuAction());
        menubar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionClear_Scene->setText(QCoreApplication::translate("MainWindow", "Clear Scene", nullptr));
#if QT_CONFIG(shortcut)
        actionClear_Scene->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_Test_Add_Street->setText(QCoreApplication::translate("MainWindow", "Test Add Street", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Hide Tests", nullptr));
        pushButton_Test_Draw_City->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
        label_eingabe->setText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_test_dijkstra->setText(QCoreApplication::translate("MainWindow", "Test Dijkstra", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_teste_was->setToolTip(QCoreApplication::translate("MainWindow", "Testet, ob Ihre Eingabe eine Zahl oder ein Text ist.", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_teste_was->setText(QCoreApplication::translate("MainWindow", "Teste was", nullptr));
        pushButton_Test_Draw_Street->setText(QCoreApplication::translate("MainWindow", "Test Draw Street", nullptr));
        lineEdit_teste_was->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_add_city->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        pushButton_fill_map->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        pushButton_test_abstract_map->setText(QCoreApplication::translate("MainWindow", "Test Abstract Map", nullptr));
        pushButton_Test_Draw_Map->setText(QCoreApplication::translate("MainWindow", "Test Draw Map", nullptr));
        pushButton_add_street->setText(QCoreApplication::translate("MainWindow", "Add Street", nullptr));
        pushButton_dijkstra_shortest_path->setText(QCoreApplication::translate("MainWindow", "Find Shortest Path", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

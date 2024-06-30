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
    QGraphicsView *graphicsView;
    QPushButton *pushButton_teste_was;
    QLabel *label_eingabe;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Test_Draw_Map;
    QLineEdit *lineEdit_teste_was;
    QPushButton *pushButton_Test_Draw_City;
    QPushButton *pushButton_Test_Draw_Street;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(454, 337);
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
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 1, 7, 1);

        pushButton_teste_was = new QPushButton(centralwidget);
        pushButton_teste_was->setObjectName("pushButton_teste_was");

        gridLayout->addWidget(pushButton_teste_was, 2, 0, 1, 1);

        label_eingabe = new QLabel(centralwidget);
        label_eingabe->setObjectName("label_eingabe");

        gridLayout->addWidget(label_eingabe, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        pushButton_Test_Draw_Map = new QPushButton(centralwidget);
        pushButton_Test_Draw_Map->setObjectName("pushButton_Test_Draw_Map");

        gridLayout->addWidget(pushButton_Test_Draw_Map, 4, 0, 1, 1);

        lineEdit_teste_was = new QLineEdit(centralwidget);
        lineEdit_teste_was->setObjectName("lineEdit_teste_was");
        lineEdit_teste_was->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_teste_was, 1, 0, 1, 1);

        pushButton_Test_Draw_City = new QPushButton(centralwidget);
        pushButton_Test_Draw_City->setObjectName("pushButton_Test_Draw_City");

        gridLayout->addWidget(pushButton_Test_Draw_City, 3, 0, 1, 1);

        pushButton_Test_Draw_Street = new QPushButton(centralwidget);
        pushButton_Test_Draw_Street->setObjectName("pushButton_Test_Draw_Street");

        gridLayout->addWidget(pushButton_Test_Draw_Street, 5, 0, 1, 1);

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
#if QT_CONFIG(tooltip)
        pushButton_teste_was->setToolTip(QCoreApplication::translate("MainWindow", "Testet, ob Ihre Eingabe eine Zahl oder ein Text ist.", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_teste_was->setText(QCoreApplication::translate("MainWindow", "Teste was", nullptr));
        label_eingabe->setText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_Test_Draw_Map->setText(QCoreApplication::translate("MainWindow", "Test Draw Map", nullptr));
        lineEdit_teste_was->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ihre Eingabe", nullptr));
        pushButton_Test_Draw_City->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
        pushButton_Test_Draw_Street->setText(QCoreApplication::translate("MainWindow", "Test Draw Street", nullptr));
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

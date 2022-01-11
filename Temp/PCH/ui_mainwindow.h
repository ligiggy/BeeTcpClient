/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Pb_Connect;
    QPushButton *Pb_Close;
    QPushButton *Pb_Write;
    QPushButton *Pb_Read;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(759, 489);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Pb_Connect = new QPushButton(centralWidget);
        Pb_Connect->setObjectName(QStringLiteral("Pb_Connect"));
        Pb_Connect->setGeometry(QRect(120, 30, 151, 51));
        Pb_Close = new QPushButton(centralWidget);
        Pb_Close->setObjectName(QStringLiteral("Pb_Close"));
        Pb_Close->setGeometry(QRect(290, 30, 151, 51));
        Pb_Write = new QPushButton(centralWidget);
        Pb_Write->setObjectName(QStringLiteral("Pb_Write"));
        Pb_Write->setGeometry(QRect(290, 110, 131, 51));
        Pb_Read = new QPushButton(centralWidget);
        Pb_Read->setObjectName(QStringLiteral("Pb_Read"));
        Pb_Read->setGeometry(QRect(510, 300, 131, 51));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 110, 151, 51));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 200, 321, 211));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Pb_Connect->setText(QApplication::translate("MainWindow", "connect", Q_NULLPTR));
        Pb_Close->setText(QApplication::translate("MainWindow", "disconnect", Q_NULLPTR));
        Pb_Write->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        Pb_Read->setText(QApplication::translate("MainWindow", "receive", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

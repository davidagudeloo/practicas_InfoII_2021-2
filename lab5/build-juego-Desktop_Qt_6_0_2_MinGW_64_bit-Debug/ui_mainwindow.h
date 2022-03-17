/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdVidas;
    QLCDNumber *lcdTiempo;
    QLCDNumber *lcdPuntaje;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTiempo;
    QLabel *labelVidas;
    QLabel *labelPuntaje;
    QPushButton *botonNuevoJuego;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 293);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 497, 209));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 210, 211, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lcdVidas = new QLCDNumber(horizontalLayoutWidget);
        lcdVidas->setObjectName(QString::fromUtf8("lcdVidas"));
        lcdVidas->setEnabled(true);
        QFont font;
        font.setBold(false);
        lcdVidas->setFont(font);
        lcdVidas->setMouseTracking(false);
        lcdVidas->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(lcdVidas);

        lcdTiempo = new QLCDNumber(horizontalLayoutWidget);
        lcdTiempo->setObjectName(QString::fromUtf8("lcdTiempo"));

        horizontalLayout->addWidget(lcdTiempo);

        lcdPuntaje = new QLCDNumber(horizontalLayoutWidget);
        lcdPuntaje->setObjectName(QString::fromUtf8("lcdPuntaje"));

        horizontalLayout->addWidget(lcdPuntaje);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 240, 201, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTiempo = new QLabel(horizontalLayoutWidget_2);
        labelTiempo->setObjectName(QString::fromUtf8("labelTiempo"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font1.setPointSize(14);
        labelTiempo->setFont(font1);

        horizontalLayout_2->addWidget(labelTiempo);

        labelVidas = new QLabel(horizontalLayoutWidget_2);
        labelVidas->setObjectName(QString::fromUtf8("labelVidas"));
        labelVidas->setFont(font1);

        horizontalLayout_2->addWidget(labelVidas);

        labelPuntaje = new QLabel(horizontalLayoutWidget_2);
        labelPuntaje->setObjectName(QString::fromUtf8("labelPuntaje"));
        labelPuntaje->setFont(font1);

        horizontalLayout_2->addWidget(labelPuntaje);

        botonNuevoJuego = new QPushButton(centralwidget);
        botonNuevoJuego->setObjectName(QString::fromUtf8("botonNuevoJuego"));
        botonNuevoJuego->setGeometry(QRect(390, 210, 101, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bomberman", nullptr));
        labelTiempo->setText(QCoreApplication::translate("MainWindow", "Vidas", nullptr));
        labelVidas->setText(QCoreApplication::translate("MainWindow", "Tiempo", nullptr));
        labelPuntaje->setText(QCoreApplication::translate("MainWindow", "Puntaje", nullptr));
        botonNuevoJuego->setText(QCoreApplication::translate("MainWindow", "Jugar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

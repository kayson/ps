/********************************************************************************
** Form generated from reading UI file 'myexample.ui'
**
** Created: Fri Oct 12 12:39:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYEXAMPLE_H
#define UI_MYEXAMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "myopengl.hh"

QT_BEGIN_NAMESPACE

class Ui_myexampleMainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    MyOpenGL *widget;
    QTextEdit *text;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myexampleMainWindow)
    {
        if (myexampleMainWindow->objectName().isEmpty())
            myexampleMainWindow->setObjectName(QString::fromUtf8("myexampleMainWindow"));
        myexampleMainWindow->resize(503, 402);
        actionQuit = new QAction(myexampleMainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(myexampleMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new MyOpenGL(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(100, 100));

        verticalLayout->addWidget(widget);

        text = new QTextEdit(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setMinimumSize(QSize(0, 20));
        text->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(text);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        myexampleMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myexampleMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 503, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        myexampleMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(myexampleMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myexampleMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(myexampleMainWindow);
        QObject::connect(menubar, SIGNAL(triggered(QAction*)), myexampleMainWindow, SLOT(handleMenuAction(QAction*)));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), myexampleMainWindow, SLOT(buttonTeapot(bool)));
        QObject::connect(pushButton, SIGNAL(clicked(bool)), myexampleMainWindow, SLOT(buttonDodecahedron(bool)));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), widget, SLOT(buttonTeapot(bool)));
        QObject::connect(pushButton, SIGNAL(clicked(bool)), widget, SLOT(buttonDodecahedron(bool)));

        QMetaObject::connectSlotsByName(myexampleMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myexampleMainWindow)
    {
        myexampleMainWindow->setWindowTitle(QApplication::translate("myexampleMainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("myexampleMainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("myexampleMainWindow", "Teapot", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("myexampleMainWindow", "Dodecahedron", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("myexampleMainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class myexampleMainWindow: public Ui_myexampleMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYEXAMPLE_H

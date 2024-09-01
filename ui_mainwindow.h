 
/********************************************************************************
** Form generated from reading UI file 'mainwindowfqzPML.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Play;
    QPushButton *Stop;
    QPushButton *FullScreen;
    QToolButton *Quit;
    QListWidget *fileList;
    QTextEdit *rawText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(696, 523);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 320, 671, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Play = new QPushButton(horizontalLayoutWidget);
        Play->setObjectName("Play");
        Play->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(10);
        font.setBold(true);
        Play->setFont(font);

        horizontalLayout->addWidget(Play);

        Stop = new QPushButton(horizontalLayoutWidget);
        Stop->setObjectName("Stop");
        Stop->setMaximumSize(QSize(100, 30));
        Stop->setFont(font);

        horizontalLayout->addWidget(Stop);

        FullScreen = new QPushButton(horizontalLayoutWidget);
        FullScreen->setObjectName("FullScreen");
        FullScreen->setMaximumSize(QSize(100, 30));
        FullScreen->setFont(font);

        horizontalLayout->addWidget(FullScreen);

        Quit = new QToolButton(horizontalLayoutWidget);
        Quit->setObjectName("Quit");
        Quit->setMaximumSize(QSize(100, 30));
        Quit->setFont(font);

        horizontalLayout->addWidget(Quit);

        fileList = new QListWidget(centralwidget);
        fileList->setObjectName("fileList");
        fileList->setGeometry(QRect(10, 380, 301, 111));
        rawText = new QTextEdit(centralwidget);
        rawText->setObjectName("rawText");
        rawText->setGeometry(QRect(390, 380, 301, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(10);
        rawText->setFont(font1);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 671, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        FullScreen->setText(QCoreApplication::translate("MainWindow", "Full Screen", nullptr));
        Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

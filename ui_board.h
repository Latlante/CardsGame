/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Board
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Board)
    {
        if (Board->objectName().isEmpty())
            Board->setObjectName(QStringLiteral("Board"));
        Board->resize(400, 300);
        menuBar = new QMenuBar(Board);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Board->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Board);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Board->addToolBar(mainToolBar);
        centralWidget = new QWidget(Board);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Board->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Board);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Board->setStatusBar(statusBar);

        retranslateUi(Board);

        QMetaObject::connectSlotsByName(Board);
    } // setupUi

    void retranslateUi(QMainWindow *Board)
    {
        Board->setWindowTitle(QApplication::translate("Board", "Board", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Board: public Ui_Board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H

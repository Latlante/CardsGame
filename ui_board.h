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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Board
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layout_PlayerArea_P2;
    QPushButton *pushButton_EndOfTurn_P2;
    QTableView *tableView_Hand_P2;
    QTableView *tableView_BenchArea_P2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QListView *listView_FightingArea_P2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_Deck_P2;
    QLabel *label_4;
    QLabel *label_Trash_P2;
    QLabel *label_6;
    QLabel *label_Rewards_P2;
    QFrame *line;
    QVBoxLayout *layout_PlayerArea_P1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QListView *listView_FightingArea_P1;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_Deck_P1;
    QLabel *label_3;
    QLabel *label_Trash_P1;
    QLabel *label_5;
    QLabel *label_Rewards_P1;
    QTableView *tableView_BenchArea_P1;
    QTableView *tableView_Hand_P1;
    QPushButton *pushButton_EndOfTurn_P1;
    QPushButton *pushButton_StartGame;

    void setupUi(QMainWindow *Board)
    {
        if (Board->objectName().isEmpty())
            Board->setObjectName(QStringLiteral("Board"));
        Board->resize(407, 544);
        centralWidget = new QWidget(Board);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        layout_PlayerArea_P2 = new QVBoxLayout();
        layout_PlayerArea_P2->setSpacing(6);
        layout_PlayerArea_P2->setObjectName(QStringLiteral("layout_PlayerArea_P2"));
        pushButton_EndOfTurn_P2 = new QPushButton(centralWidget);
        pushButton_EndOfTurn_P2->setObjectName(QStringLiteral("pushButton_EndOfTurn_P2"));

        layout_PlayerArea_P2->addWidget(pushButton_EndOfTurn_P2);

        tableView_Hand_P2 = new QTableView(centralWidget);
        tableView_Hand_P2->setObjectName(QStringLiteral("tableView_Hand_P2"));

        layout_PlayerArea_P2->addWidget(tableView_Hand_P2);

        tableView_BenchArea_P2 = new QTableView(centralWidget);
        tableView_BenchArea_P2->setObjectName(QStringLiteral("tableView_BenchArea_P2"));

        layout_PlayerArea_P2->addWidget(tableView_BenchArea_P2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setPointSize(14);
        label_8->setFont(font);

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        listView_FightingArea_P2 = new QListView(centralWidget);
        listView_FightingArea_P2->setObjectName(QStringLiteral("listView_FightingArea_P2"));

        horizontalLayout_3->addWidget(listView_FightingArea_P2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_Deck_P2 = new QLabel(centralWidget);
        label_Deck_P2->setObjectName(QStringLiteral("label_Deck_P2"));

        gridLayout_2->addWidget(label_Deck_P2, 0, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_Trash_P2 = new QLabel(centralWidget);
        label_Trash_P2->setObjectName(QStringLiteral("label_Trash_P2"));

        gridLayout_2->addWidget(label_Trash_P2, 1, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_Rewards_P2 = new QLabel(centralWidget);
        label_Rewards_P2->setObjectName(QStringLiteral("label_Rewards_P2"));

        gridLayout_2->addWidget(label_Rewards_P2, 2, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);


        layout_PlayerArea_P2->addLayout(horizontalLayout_3);

        layout_PlayerArea_P2->setStretch(3, 1);

        verticalLayout->addLayout(layout_PlayerArea_P2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        layout_PlayerArea_P1 = new QVBoxLayout();
        layout_PlayerArea_P1->setSpacing(6);
        layout_PlayerArea_P1->setObjectName(QStringLiteral("layout_PlayerArea_P1"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_2->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        listView_FightingArea_P1 = new QListView(centralWidget);
        listView_FightingArea_P1->setObjectName(QStringLiteral("listView_FightingArea_P1"));

        horizontalLayout_2->addWidget(listView_FightingArea_P1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_Deck_P1 = new QLabel(centralWidget);
        label_Deck_P1->setObjectName(QStringLiteral("label_Deck_P1"));

        gridLayout->addWidget(label_Deck_P1, 0, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_Trash_P1 = new QLabel(centralWidget);
        label_Trash_P1->setObjectName(QStringLiteral("label_Trash_P1"));

        gridLayout->addWidget(label_Trash_P1, 1, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_Rewards_P1 = new QLabel(centralWidget);
        label_Rewards_P1->setObjectName(QStringLiteral("label_Rewards_P1"));

        gridLayout->addWidget(label_Rewards_P1, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        layout_PlayerArea_P1->addLayout(horizontalLayout_2);

        tableView_BenchArea_P1 = new QTableView(centralWidget);
        tableView_BenchArea_P1->setObjectName(QStringLiteral("tableView_BenchArea_P1"));

        layout_PlayerArea_P1->addWidget(tableView_BenchArea_P1);

        tableView_Hand_P1 = new QTableView(centralWidget);
        tableView_Hand_P1->setObjectName(QStringLiteral("tableView_Hand_P1"));

        layout_PlayerArea_P1->addWidget(tableView_Hand_P1);

        pushButton_EndOfTurn_P1 = new QPushButton(centralWidget);
        pushButton_EndOfTurn_P1->setObjectName(QStringLiteral("pushButton_EndOfTurn_P1"));

        layout_PlayerArea_P1->addWidget(pushButton_EndOfTurn_P1);

        layout_PlayerArea_P1->setStretch(0, 1);

        verticalLayout->addLayout(layout_PlayerArea_P1);

        pushButton_StartGame = new QPushButton(centralWidget);
        pushButton_StartGame->setObjectName(QStringLiteral("pushButton_StartGame"));

        verticalLayout->addWidget(pushButton_StartGame);

        Board->setCentralWidget(centralWidget);

        retranslateUi(Board);

        QMetaObject::connectSlotsByName(Board);
    } // setupUi

    void retranslateUi(QMainWindow *Board)
    {
        Board->setWindowTitle(QApplication::translate("Board", "Board", Q_NULLPTR));
        pushButton_EndOfTurn_P2->setText(QApplication::translate("Board", "Fin du tour", Q_NULLPTR));
        label_8->setText(QApplication::translate("Board", "PLAYER 2", Q_NULLPTR));
        label_2->setText(QApplication::translate("Board", "Deck:", Q_NULLPTR));
        label_Deck_P2->setText(QApplication::translate("Board", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("Board", "Trash:", Q_NULLPTR));
        label_Trash_P2->setText(QApplication::translate("Board", "0", Q_NULLPTR));
        label_6->setText(QApplication::translate("Board", "Rewards:", Q_NULLPTR));
        label_Rewards_P2->setText(QApplication::translate("Board", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("Board", "PLAYER 1", Q_NULLPTR));
        label->setText(QApplication::translate("Board", "Deck:", Q_NULLPTR));
        label_Deck_P1->setText(QApplication::translate("Board", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("Board", "Trash:", Q_NULLPTR));
        label_Trash_P1->setText(QApplication::translate("Board", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("Board", "Rewards:", Q_NULLPTR));
        label_Rewards_P1->setText(QApplication::translate("Board", "0", Q_NULLPTR));
        pushButton_EndOfTurn_P1->setText(QApplication::translate("Board", "Fin du tour", Q_NULLPTR));
        pushButton_StartGame->setText(QApplication::translate("Board", "Commencer le jeu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Board: public Ui_Board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H

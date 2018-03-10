#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QMultiMap>
#include "gamemanager.h"

namespace Ui {
class Board;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    ~Board();

private slots:
    void onCountChanged_Deck_P1(int count);
    void onCountChanged_Rewards_P1(int count);
    void onCountChanged_Trash_P1(int count);
    void onCountChanged_Deck_P2(int count);
    void onCountChanged_Rewards_P2(int count);
    void onCountChanged_Trash_P2(int count);

    void onDClickedCell_Hand_P1(const QModelIndex &index);
    void onDClickedCell_Hand_P2(const QModelIndex &index);
    void onDClickedCell_Bench_P1(const QModelIndex &index);
    void onDClickedCell_Bench_P2(const QModelIndex &index);
    void onDClickedCell_Fight_P1(const QModelIndex &index);
    void onDClickedCell_Fight_P2(const QModelIndex &index);


    void onClicked_pushButton_EndOfTurn();

    //void onCountChanged_Packets(int count);

    void onClicked_pushButton_StartGame();

    void onCanPlayChanged_Player(bool state);

private:
    Ui::Board *ui;
    GameManager *m_gameManager;
    QMultiMap<Player*,QWidget*> m_listWidgetsByPlayer;

    Player* findPlayerByWidget(QWidget* wid);
};

#endif // BOARD_H

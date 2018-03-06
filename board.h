#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
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

    void onClicked_pushButton_DrawCards();

private:
    Ui::Board *ui;
    GameManager *m_gameManager;
};

#endif // BOARD_H

#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>

namespace Ui {
class Board;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    ~Board();

private:
    Ui::Board *ui;
};

#endif // BOARD_H

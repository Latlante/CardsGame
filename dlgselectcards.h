#ifndef DLGSELECTCARDS_H
#define DLGSELECTCARDS_H

#include <QDialog>

class AbstractCard;

namespace Ui {
class DlgSelectCards;
}

class DlgSelectCards : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSelectCards(QWidget *parent = 0);
    ~DlgSelectCards();

    QList<AbstractCard*> listOfSelectedCards();
    QList<AbstractCard*> listOfRandomCards();

private:
    Ui::DlgSelectCards *ui;
};

#endif // DLGSELECTCARDS_H

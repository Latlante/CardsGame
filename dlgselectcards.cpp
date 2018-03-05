#include "dlgselectcards.h"
#include "ui_dlgselectcards.h"

#include "src_Cards/abstractcard.h"

DlgSelectCards::DlgSelectCards(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSelectCards)
{
    ui->setupUi(this);
}

DlgSelectCards::~DlgSelectCards()
{
    delete ui;
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
QList<AbstractCard*> DlgSelectCards::listOfSelectedCards()
{

}

QList<AbstractCard*> DlgSelectCards::listOfRandomCards()
{

}

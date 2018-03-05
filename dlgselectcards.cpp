#include "dlgselectcards.h"
#include "ui_dlgselectcards.h"

#include "src_Cards/abstractcard.h"
#include "utils.h"
#include "common/database.h"

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
    QList<AbstractCard*> listCards;
    Database db;

    for(int i=0;i<6;++i)
    {
        int idPokemon = Utils::randomValue(0, 10);
        listCards.append(db.cardById(idPokemon));
    }

    for(int i=0;i<4;++i)
    {
        int idEnergy = Utils::randomValue(INDEX_START_ENERGIES, INDEX_START_ENERGIES+10);
        listCards.append(db.cardById(idEnergy));
    }

    return listCards;
}

#include "bencharea.h"

#include <QDebug>
#include "src_Cards/cardpokemon.h"

BenchArea::BenchArea(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

BenchArea::~BenchArea()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int BenchArea::maxCards()
{
	return 5;
}

QVariant BenchArea::data(const QModelIndex& index, int role) const
{
    int iRow = index.row();
    if (iRow < 0 || iRow >= countCard())
    {
        qCritical() << __PRETTY_FUNCTION__ << "bad row num : " << iRow;
        return QVariant();
    }

    if (Qt::DisplayRole == role)
    {
        AbstractCard* abCard = m_listCards[index.row()];

        if (abCard != NULL)
        {
            if (abCard->type() == AbstractCard::TypeOfCard_Pokemon)
            {
                CardPokemon *cardPok = static_cast<CardPokemon*>(abCard);

                QString messageToDisplay = cardPok->name();
                messageToDisplay += " (" + QString::number(cardPok->lifeLeft()) + "/" + QString::number(cardPok->lifeTotal()) + ")";
                messageToDisplay += " : Energies=" + QString::number(cardPok->countEnergies());

                return messageToDisplay;
            }
            else
            {
                return "Erreur de carte: La carte n'est pas du bon type:" + abCard->type();
            }
        }
        else
        {
            return "Erreur de carte: Card is NULL";
        }
    }

    return QVariant::Invalid;
}

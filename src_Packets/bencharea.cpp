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
    //qDebug() << __PRETTY_FUNCTION__ << index << role;

    int iRow = index.row();
    int iColumn = index.column();
    if ((iRow < 0) || (iRow >= rowCount()) || (iColumn < 0) || (iColumn >= columnCount()))
    {
        qCritical() << __PRETTY_FUNCTION__ << "bad column num : " << iRow;
        return QVariant();
    }

    if (Qt::DisplayRole == role)
    {
        AbstractCard* abCard = m_listCards[iColumn];

        if (abCard != NULL)
        {
            if (abCard->type() == AbstractCard::TypeOfCard_Pokemon)
            {
                CardPokemon *cardPok = static_cast<CardPokemon*>(abCard);

                switch(iRow)
                {
                case 0: //Nom du pokemon
                    return cardPok->name();
                case 1: //Vie restante et total
                    return QString::number(cardPok->lifeLeft()) + "/" + QString::number(cardPok->lifeTotal());
                case 2: //Energies
                    return "Energies=" + QString::number(cardPok->countEnergies());
                default:
                    break;
                }

                /*QString messageToDisplay = cardPok->name();
                messageToDisplay += " (" + QString::number(cardPok->lifeLeft()) + "/" + QString::number(cardPok->lifeTotal()) + ")";
                messageToDisplay += " : Energies=" + QString::number(cardPok->countEnergies());

                return messageToDisplay;*/
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

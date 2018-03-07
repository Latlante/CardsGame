#include "fightarea.h"

#include <QDebug>
#include "src_Cards/cardpokemon.h"

FightArea::FightArea(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

FightArea::~FightArea()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int FightArea::maxCards()
{
    return 1;
}

bool FightArea::addNewCard(AbstractCard *newCard)
{
    bool status = false;

    if((newCard != NULL) && (newCard->type() == AbstractCard::TypeOfCard_Pokemon))
    {
        CardPokemon *pokemon = static_cast<CardPokemon*>(newCard);

        if(pokemon != NULL)
        {
            status = AbstractPacket::addNewCard(newCard);

            if(status == true)
            {
                connect(pokemon, &CardPokemon::lifeLeftChanged, this, &FightArea::updateAllData);
                connect(pokemon, &CardPokemon::statusChanged, this, &FightArea::updateAllData);
                connect(pokemon, &CardPokemon::listEnergiesChanged, this, &FightArea::updateAllData);
            }
        }

    }

    return status;
}

CardPokemon* FightArea::pokemonFighting(int index)
{
    CardPokemon* pokemon = NULL;

    AbstractCard* abCard = card(index);

    if(abCard != NULL)
    {
        pokemon = static_cast<CardPokemon*>(abCard);
    }

    return pokemon;
}

QVariant FightArea::data(const QModelIndex& index, int role) const
{
    int iRow = index.row();
    if (iRow < 0 || iRow >= rowCount())
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
                messageToDisplay += " : Energies=" + QString::number(cardPok->countEnergies()) + "\n";
                messageToDisplay += " Attack1: 50\n";
                messageToDisplay += " Attack2: 30";

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

/************************************************************
*****			FONCTIONS SLOTS PRIVEES					*****
************************************************************/
void FightArea::updateAllData()
{
    emit dataChanged(index(0, 0), index(rowCount(), 0));
}

/************************************************************
*****				FONCTIONS PRIVEES					*****
************************************************************/


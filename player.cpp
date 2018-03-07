#include "player.h"

#include <QDebug>
#include "src_Cards/abstractcard.h"
#include "src_Cards/cardaction.h"
#include "src_Cards/cardenergy.h"
#include "src_Cards/cardpokemon.h"
#include "src_Packets/bencharea.h"
#include "src_Packets/fightarea.h"
#include "src_Packets/packetdeck.h"
#include "src_Packets/packethand.h"
#include "src_Packets/packetrewards.h"
#include "src_Packets/packettrash.h"

Player::Player(QString name, QList<AbstractCard*> listCards, QObject *parent) :
	QObject(parent),
    m_name(name),
    m_canPlay(false),
    m_bench(new BenchArea()),
    m_deck(new PacketDeck(listCards)),
    m_fight(new FightArea()),
    m_hand(new PacketHand()),
    m_rewards(new PacketRewards()),
    m_trash(new PacketTrash())
{
	
}

Player::~Player()
{
    delete m_bench;
    delete m_deck;
    delete m_fight;
    delete m_hand;
    delete m_rewards;
    delete m_trash;
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
BenchArea* Player::bench()
{
    return m_bench;
}

PacketDeck* Player::deck()
{
	return m_deck;
}

FightArea* Player::fight()
{
    return m_fight;
}

PacketHand* Player::hand()
{
	return m_hand;
}

PacketRewards* Player::rewards()
{
    return m_rewards;
}

PacketTrash* Player::trash()
{
    return m_trash;
}

void Player::init(QList<AbstractCard*> listCards)
{
	
}

void Player::newTurn()
{
    m_canPlay = true;
}

void Player::skipYourTurn()
{
    emit endOfTurn();
}

void Player::blockPlayer()
{
    m_canPlay = false;
}

bool Player::isPlaying()
{
    return m_canPlay;
}

void Player::drawOneCard()
{
    qDebug() << m_name << " - "<< __PRETTY_FUNCTION__;

    if (!m_hand->isFull())
    {
        AbstractCard* newCard = m_deck->drawCard();
        qDebug() << "drawOneCard" << newCard->name();
        m_hand->addNewCard(newCard);
    }
    else
    {
        qCritical() << __PRETTY_FUNCTION__ << ", Packet full";
    }
}

void Player::attack()
{
    qDebug() << m_name << " - "<< __PRETTY_FUNCTION__;


}

bool Player::isWinner()
{
    return 0 == m_rewards->rowCount();
}

bool Player::moveCardFromHandToBench(const QModelIndex &indexHand, const QModelIndex &indexBench)
{
    bool moveSuccess = false;

    AbstractCard* cardToMove = hand()->card(indexHand.row());

    if (cardToMove != NULL)
    {
        //On autorise uniquement les cartes de type Pokemon a être posé sur le banc
        if (cardToMove->type() == AbstractCard::TypeOfCard_Pokemon)
        {
            CardPokemon* cardPok = static_cast<CardPokemon*>(cardToMove);

            //On refuse les évolutions
            if ((cardPok != NULL) && (cardPok->isBase() == true))
            {
                moveSuccess = moveCardFromPacketToAnother(hand(), bench(), indexHand.row());
            }
            else
            {
                qDebug() << __PRETTY_FUNCTION__ << ", cardPok n'est pas une base";
            }
        }
        else if (cardToMove->type() == AbstractCard::TypeOfCard_Energy)
        {
            CardEnergy* cardEn = static_cast<CardEnergy*>(cardToMove);

            if (cardEn != NULL)
            {
                //On récupére la carte Pokémon a laquelle l'associer
                AbstractCard* cardToAssociate = bench()->card(indexBench.row());

                if ((cardToAssociate != NULL) && (cardToAssociate->type() == AbstractCard::TypeOfCard_Pokemon))
                {
                    CardPokemon* pokemonToAssociate = static_cast<CardPokemon*>(cardToAssociate);

                    if (pokemonToAssociate != NULL)
                    {
                        pokemonToAssociate->addEnergy(cardEn);
                        moveSuccess = true;
                    }
                }
            }
        }
        else
        {
            qDebug() << __PRETTY_FUNCTION__ << ", cardToMove n'est pas du bon type:" << cardToMove->type();
        }
    }
    else
    {
        qDebug() << __PRETTY_FUNCTION__ << ", cardToMove is NULL";
    }

    return moveSuccess;
}

bool Player::moveCardFromBenchToFight(const QModelIndex &index)
{
    bool moveSuccess = false;

    AbstractCard* cardToMove = bench()->card(index.row());

    if (cardToMove != NULL)
    {
        //On autorise uniquement les cartes de type Pokemon a être posé sur le banc
        if (cardToMove->type() == AbstractCard::TypeOfCard_Pokemon)
        {
            CardPokemon* cardPok = static_cast<CardPokemon*>(cardToMove);

            //On refuse les évolutions
            if (cardPok->isBase() == true)
            {
                moveSuccess = moveCardFromPacketToAnother(bench(), fight(), index.row());
            }
            else
            {
                qDebug() << __PRETTY_FUNCTION__ << ", cardPok n'est pas une base";
            }
        }
        else
        {
            qDebug() << __PRETTY_FUNCTION__ << ", cardToMove n'est pas du bon type:" << cardToMove->type();
        }
    }
    else
    {
        qDebug() << __PRETTY_FUNCTION__ << ", cardToMove is NULL";
    }

    return moveSuccess;
}

bool Player::moveCardFromFightToTrash(const QModelIndex &index)
{
    return moveCardFromPacketToAnother(fight(), trash(), index.row());
}

/************************************************************
*****				FONCTIONS PRIVEES					*****
************************************************************/
bool Player::moveCardFromPacketToAnother(AbstractPacket *source, AbstractPacket *destination, int index)
{
    bool moveSuccess = false;

    if (destination->isFull() == false)
    {
        AbstractCard* cardToMove = source->takeACard(index);

        if (cardToMove != NULL)
        {
            destination->addNewCard(cardToMove);
            moveSuccess = true;
        }
        else
        {
            qCritical() << __PRETTY_FUNCTION__ << "Card is NULL";

        }
    }

    return moveSuccess;
}

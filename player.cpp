#include "player.h"

#include "src_Cards/abstractcard.h"
#include "src_Packets/bencharea.h"
#include "src_Packets/fightarea.h"
#include "src_Packets/packetdeck.h"
#include "src_Packets/packethand.h"
#include "src_Packets/packetrewards.h"
#include "src_Packets/packettrash.h"

Player::Player(QString name, QList<AbstractCard*> listCards, QObject *parent = NULL) :
	QObject(parent),
	m_name(name)
{
	
}

Player::~Player()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
PacketDeck* Player::deck()
{
	return m_deck;
}

PacketRewards* Player::rewards()
{
	return m_rewards;
}

PacketHand* Player::hand()
{
	return m_hand;
}

BenchArea* Player::bench()
{
	return m_bench;
}

FightArea* Player::fight()
{
	return m_fight;
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
	
}

void Player::blockPlayer()
{
	
}

void Player::drawOneCard()
{
	AbstractCard* newCard = m_deck->drawCard();
	m_hand->addNewCard(newCard);
}

bool Player::isWinner()
{
	return 0 == m_rewards.rowCount();
}

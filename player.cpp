#include "player.h"

#include "src_Cards/abstractcard.h"
#include "src_Packets/bencharea.h"
#include "src_Packets/fightarea.h"
#include "src_Packets/packetdeck.h"
#include "src_Packets/packethand.h"
#include "src_Packets/packetrewards.h"
#include "src_Packets/packettrash.h"

Player::Player(QString name, QList<AbstractCard*> listCards, QObject *parent) :
	QObject(parent),
    m_name(name),
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
    return 0 == m_rewards->rowCount();
}

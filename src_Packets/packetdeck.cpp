#include "packetdeck.h"

PacketDeck::PacketDeck(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

PacketDeck::~PacketDeck()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int PacketDeck::maxCards()
{
    return 10;
}

void PacketDeck::mixCards()
{
	
}

Card* PacketDeck::drawCard()
{
	return m_listCards.takeFirst();
}

QList<Card*> PacketDeck::drawCards(int count)
{
	QList<Card*> listCards;
	
	for(int i=0;i<count;++i)
	{
		listCards.append(drawCard());
	}
	
	return listCards;
}

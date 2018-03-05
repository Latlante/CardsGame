#include "packetdeck.h"

#include "src_Cards/abstractcard.h"

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

AbsractCard *PacketDeck::drawCard()
{
	return m_listCards.takeFirst();
}

QList<AbsractCard*> PacketDeck::drawCards(int count)
{
	QList<Card*> listCards;
	
	for(int i=0;i<count;++i)
	{
		listCards.append(drawCard());
	}
	
	return listCards;
}

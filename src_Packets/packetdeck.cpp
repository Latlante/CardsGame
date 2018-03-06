#include "packetdeck.h"

#include "src_Cards/abstractcard.h"

PacketDeck::PacketDeck(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
    mixCards();
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

AbstractCard *PacketDeck::drawCard()
{
    return takeACard(0);
}

QList<AbstractCard*> PacketDeck::drawCards(int count)
{
    QList<AbstractCard*> listCards;
	
	for(int i=0;i<count;++i)
	{
		listCards.append(drawCard());
	}
	
	return listCards;
}

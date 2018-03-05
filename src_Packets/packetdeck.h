#ifndef PACKETDECK_H
#define PACKETDECK_H

#include "abstractpacket.h"

class PacketDeck : public AbstractPacket
{
public:
    PacketDeck();
    virtual ~PacketDeck(QList<AbstractCard*> listCards = QList<AbstractCard*>());
	
	int maxCards();
	void mixCards();
	Card* drawCard();
	QList<Card*> drawCards(int count);

private:
};

#endif // PACKETDECK_H

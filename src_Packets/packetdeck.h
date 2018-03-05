#ifndef PACKETDECK_H
#define PACKETDECK_H

#include "abstractpacket.h"

class AbsractCard;

class PacketDeck : public AbstractPacket
{
public:
    PacketDeck(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~PacketDeck();
	
	int maxCards();
	void mixCards();
    AbsractCard* drawCard();
    QList<AbsractCard *> drawCards(int count);

private:
};

#endif // PACKETDECK_H

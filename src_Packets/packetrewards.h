#ifndef PACKETREWARDS_H
#define PACKETREWARDS_H

#include "abstractpacket.h"

class PacketRewards : public AbstractPacket
{
public:
    PacketRewards(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~PacketRewards();
	
	int maxCards();

private:

};

#endif // PACKETREWARDS_H

#ifndef PACKETREWARDS_H
#define PACKETREWARDS_H

#include "abstractpacket.h"

class PacketRewards : public AbstractPacket
{
public:
    PacketRewards();
    virtual ~PacketRewards(QList<AbstractCard*> listCards = QList<AbstractCard*>());
	
	int maxCards();

private:

};

#endif // PACKETREWARDS_H

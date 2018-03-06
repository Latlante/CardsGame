#ifndef PACKETHAND_H
#define PACKETHAND_H

#include "abstractpacket.h"

class PacketHand : public AbstractPacket
{
public:
    PacketHand();
    virtual ~PacketHand();
	
	int maxCards();

    AbstractCard* takeACard(int index) override;

private:

};

#endif // PACKETHAND_H

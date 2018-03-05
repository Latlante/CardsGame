#ifndef PACKETHAND_H
#define PACKETHAND_H

#include "abstractpacket.h"

class PacketHand : public AbstractPacket
{
public:
    PacketHand();
    virtual ~PacketHand();
	
	int maxCards();

private:

};

#endif // PACKETHAND_H

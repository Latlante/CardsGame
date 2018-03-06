#include "packethand.h"

PacketHand::PacketHand()
{
	
}

PacketHand::~PacketHand()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int PacketHand::maxCards()
{
    return 20;
}

AbstractCard* PacketHand::takeACard(int index)
{
    return AbstractPacket::takeACard(index);
}

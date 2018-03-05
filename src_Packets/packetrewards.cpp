#include "packetrewards.h"

PacketRewards::PacketRewards(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

PacketRewards::~PacketRewards()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int PacketRewards::maxCards()
{
	return 6;
}

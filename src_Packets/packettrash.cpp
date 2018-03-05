#include "packettrash.h"

PacketTrash::PacketTrash(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

PacketTrash::~PacketTrash()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int PacketTrash::maxCards()
{
	return 60;
}

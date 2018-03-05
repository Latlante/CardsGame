#ifndef PACKETTRASH_H
#define PACKETTRASH_H

#include "abstractpacket.h"

class PacketTrash : public AbstractPacket
{
public:
    PacketTrash();
    virtual ~PacketTrash(QList<AbstractCard*> listCards = QList<AbstractCard*>());
	
	int maxCards();

private:

};

#endif // PACKETTRASH_H

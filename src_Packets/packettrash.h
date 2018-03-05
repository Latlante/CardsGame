#ifndef PACKETTRASH_H
#define PACKETTRASH_H

#include "abstractpacket.h"

class PacketTrash : public AbstractPacket
{
public:
    PacketTrash(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~PacketTrash();
	
	int maxCards();

private:

};

#endif // PACKETTRASH_H

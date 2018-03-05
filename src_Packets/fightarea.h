#ifndef FIGHTAREA_H
#define FIGHTAREA_H

#include "abstractpacket.h"

class FightArea : public AbstractPacket
{
public:
    FightArea();
    virtual ~FightArea(QList<AbstractCard*> listCards = QList<AbstractCard*>());
	
	int maxCards();

private:

};

#endif // FIGHTAREA_H

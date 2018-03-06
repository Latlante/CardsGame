#ifndef FIGHTAREA_H
#define FIGHTAREA_H

#include "abstractpacket.h"

class FightArea : public AbstractPacket
{
public:
    FightArea(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~FightArea();
	
    int maxCards() override;

private:

};

#endif // FIGHTAREA_H

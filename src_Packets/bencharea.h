#ifndef BENCHAREA_H
#define BENCHAREA_H

#include "abstractpacket.h"

class BenchArea : public AbstractPacket
{
public:
    BenchArea(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~BenchArea();
	
	int maxCards();

private:

};

#endif // BENCHAREA_H

#ifndef BENCHAREA_H
#define BENCHAREA_H

#include "abstractpacket.h"

class BenchArea : public AbstractPacket
{
public:
    BenchArea();
    virtual ~BenchArea(QList<AbstractCard*> listCards = QList<AbstractCard*>());
	
	int maxCards();

private:

};

#endif // BENCHAREA_H

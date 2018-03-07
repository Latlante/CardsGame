#ifndef BENCHAREA_H
#define BENCHAREA_H

#include "abstractpacket.h"

class BenchArea : public AbstractPacket
{
public:
    BenchArea(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~BenchArea();
	
	int maxCards();

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:

};

#endif // BENCHAREA_H

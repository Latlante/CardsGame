#ifndef FIGHTAREA_H
#define FIGHTAREA_H

#include "abstractpacket.h"

class CardPokemon;

class FightArea : public AbstractPacket
{
public:
    FightArea(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~FightArea();
	
    int maxCards() override;

    CardPokemon* pokemonFighting(int index);

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:

};

#endif // FIGHTAREA_H

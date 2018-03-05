#include "fightarea.h"

FightArea::FightArea(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

FightArea::~FightArea()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int FightArea::maxCards()
{
	return 5;
}

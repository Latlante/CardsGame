#include "bencharea.h"

BenchArea::BenchArea(QList<AbstractCard*> listCards) :
	AbstractPacket(listCards)
{
	
}

BenchArea::~BenchArea()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int BenchArea::maxCards()
{
	return 5;
}

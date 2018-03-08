#include "abstractcard.h"

AbstractCard::AbstractCard(unsigned short id, const QString& name) :
	m_id(id),
    m_name(name)
{
	
}

AbstractCard::~AbstractCard()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
int AbstractCard::id()
{
    return m_id;
}

const QString AbstractCard::name()
{
	return m_name;
}

void AbstractCard::setName(const QString& name)
{
	m_name = name;
}

#include "cardenergy.h"

CardEnergy::CardEnergy(unsigned short id, const QString& name, AbstractCard::Enum_element element, unsigned short quantity) :
    AbstractCard(id, name),
	m_element(element),
	m_quantity(quantity)
{
	
}

CardEnergy::~CardEnergy()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractCard::Enum_typeOfCard CardEnergy::type()
{
    return AbstractCard::TypeOfCard_Energy;
}

AbstractCard::Enum_element CardEnergy::element()
{
	return m_element;
}

void CardEnergy::setElement(AbstractCard::Enum_element element)
{
	m_element = element;
}

unsigned short CardEnergy::quantity()
{
	return m_quantity;
}

void CardEnergy::setQuantity(unsigned short quantity)
{
	m_quantity = quantity;
}

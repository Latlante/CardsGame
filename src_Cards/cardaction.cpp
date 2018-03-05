#include "cardaction.h"

CardAction::CardAction(unsigned short id, const QString& name, const QString& description, AbstractAction* action) :
	AbstractCard(id, name),
	m_description(description),
	m_action(action)
{
	
}

CardAction::~CardAction()
{
	delete m_action;
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractCard::Enum_typeOfCard CardAction::type()
{
	return AbstractCard::TypeOfCard_Action;
}

const QString CardAction::description()
{
	return m_description;
}

AbstractAction* CardAction::action()
{
	return m_action;
}

void CardAction::executeAction()
{
	m_action->execute();
}
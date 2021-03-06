#ifndef CARDACTION_H
#define CARDACTION_H

#include "abstractcard.h"

class CardAction : public AbstractCard
{
public:
    CardAction(unsigned short id, const QString& name, const QString& description/*, AbstractAction* action*/);
    ~CardAction();
	
	AbstractCard::Enum_typeOfCard type();
	const QString description();
    //AbstractAction* action();
	
	void executeAction();

private:
	QString m_description;
    //AbstractAction* m_action;
};

#endif // CARDACTION_H

#include "actionprotectedagainstdamage.h"

ActionProtectedAgainstDamage::ActionProtectedAgainstDamage(unsigned short id, const QString &name) :
    AbstractAction(id, name)
{

}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractAction::Enum_typeOfAction ActionProtectedAgainstDamage::type()
{
    return AbstractAction::Action_ProtectedAgainstDamage;
}

void ActionProtectedAgainstDamage::executeAction()
{

}

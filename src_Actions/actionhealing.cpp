#include "actionhealing.h"

#include "gamemanager.h"

ActionHealing::ActionHealing(unsigned short id, const QString &name, unsigned short pv) :
    AbstractAction(id, name),
    m_pv(pv)
{

}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractAction::Enum_typeOfAction ActionHealing::type()
{
    return AbstractAction::Action_Healing;
}

void ActionHealing::executeAction()
{

}

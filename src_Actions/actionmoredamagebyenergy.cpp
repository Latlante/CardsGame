#include "actionmoredamagebyenergy.h"

ActionMoreDamageByEnergy::ActionMoreDamageByEnergy(unsigned short id, const QString &name, unsigned short damageByEnergy) :
    AbstractAction(id, name),
    m_damageByEnergy(damageByEnergy)
{

}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractAction::Enum_typeOfAction ActionMoreDamageByEnergy::type()
{
    return AbstractAction::Action_MoreDamageByEnergy;
}

void ActionMoreDamageByEnergy::executeAction()
{

}

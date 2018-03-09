#include "actionremoveenergyattached.h"

#include "gamemanager.h"

ActionRemoveEnergyAttached::ActionRemoveEnergyAttached(unsigned short id, const QString &name, unsigned short numberOfEnergiesToRemoved) :
    AbstractAction(id, name),
    m_numberOfEnergiesToRemoved(numberOfEnergiesToRemoved)
{

}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractAction::Enum_typeOfAction ActionRemoveEnergyAttached::type()
{
    return AbstractAction::Action_RemoveEnergyAttached;
}

void ActionRemoveEnergyAttached::executeAction()
{

}

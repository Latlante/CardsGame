#include "actionmoredamagebyenergy.h"

ActionMoreDamageByEnergy::ActionMoreDamageByEnergy(unsigned short damageByEnergy) :
    AbstractAction(),
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
	GameManager *manager = GameManager::instance();

    if(manager != NULL)
    {
        Player* playerAttacked = manager->playerAttacked();

        if(playerAttacked != NULL)
        {
            FightArea *fightAr = playerAttacked->fight();

            if(fightAr != NULL)
            {
                CardPokemon *pokemonAttacked = fightAr->pokemonFighting(0);

                if(pokemonAttacked != NULL)
                {
                    pokemonAttacked->setStatus(m_status);
                }
                else
                    qCritical() << __PRETTY_FUNCTION__ << ", pokemonAttacked is NULL";
            }
            else
                qCritical() << __PRETTY_FUNCTION__ << ", fightAr is NULL";
        }
        else
            qCritical() << __PRETTY_FUNCTION__ << ", playerAttacked is NULL";
    }
    else
        qCritical() << __PRETTY_FUNCTION__ << ", manager is NULL";
}

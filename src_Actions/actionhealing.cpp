#include "actionhealing.h"

#include "gamemanager.h"

ActionHealing::ActionHealing(unsigned short pv) :
    AbstractAction(),
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
	GameManager *manager = GameManager::instance();

    if(manager != NULL)
    {
        Player* currentPlayer = manager->currentPlayer();

        if(currentPlayer != NULL)
        {
            FightArea *fightAr = currentPlayer->fight();

            if(fightAr != NULL)
            {
                CardPokemon *pokemonAttacking = fightAr->pokemonFighting(0);

                if(pokemonAttacking != NULL)
                {
                    pokemonAttacking->restoreLife(m_pv);
                }
                else
                    qCritical() << __PRETTY_FUNCTION__ << ", pokemonAttacking is NULL";
            }
            else
                qCritical() << __PRETTY_FUNCTION__ << ", fightAr is NULL";
        }
        else
            qCritical() << __PRETTY_FUNCTION__ << ", currentPlayer is NULL";
    }
    else
        qCritical() << __PRETTY_FUNCTION__ << ", manager is NULL";
}

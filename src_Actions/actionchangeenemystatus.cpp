#include "actionchangeenemystatus.h"

#include "gamemanager.h"
#include "src_Packets/fightarea.h"

ActionChangeEnemyStatus::ActionChangeEnemyStatus(unsigned short id, const QString &name, CardPokemon::Enum_statusOfPokemon status) :
    AbstractAction(id, name),
    m_status(status)
{

}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractAction::Enum_typeOfAction ActionChangeEnemyStatus::type()
{
    return AbstractAction::Action_ChangeEnemyStatus;
}

void ActionChangeEnemyStatus::executeAction()
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
#include "cardpokemon.h"

#include "cardenergy.h"

CardPokemon::CardPokemon(unsigned short id, 
			const QString& name, 
			AbstractCard::Enum_element element,
			unsigned short lifeTotal,
			QList<AttackData> listAttacks,
			short evolutionFrom) :
	AbstractCard(id, name),
	m_element(element),
	m_lifeTotal(lifeTotal),
	m_lifeLeft(lifeTotal),
	m_status(Status_Normal),
	m_listAttacks(listAttacks),
	m_listEnergies(QList<CardEnergy*>()),
	m_evolutionFrom(evolutionFrom)
{
	
}
				
CardPokemon::~CardPokemon()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
AbstractCard::Enum_typeOfCard CardPokemon::type()
{
	return AbstractCard::TypeOfCard_Pokemon;
}

unsigned short CardPokemon::lifeTotal()
{
	return m_lifeTotal;
}

unsigned short CardPokemon::lifeLeft()
{
	return m_lifeLeft;
}

CardPokemon::Enum_statusOfPokemon CardPokemon::status()
{
	return m_status;
}

QList<AttackData> CardPokemon::listAttacks()
{
	return m_listAttacks;
}

unsigned short CardPokemon::countEnergies()
{
	return m_listEnergies.count();
}

unsigned short CardPokemon::countEnergies(Enum_element element)
{
	int count = 0;
	
	foreach (CardEnergy* energy, m_listEnergies)
	{
        if (energy->element() == element)
			count++;
	}
	
	return count;
}

bool CardPokemon::tryToAttack(int indexAttack, CardPokemon& enemy)
{
	bool statusBack = false;
	
	if ((0 > indexAttack) || (m_listAttacks.count() <= indexAttack))
        throw "CardPokemon::attack() => index incohérent (" + QString::number(indexAttack) + ")";
	
	if (true == hasEnoughEnergies(indexAttack))
	{
		if (true == canAttackFromStatus())
		{
			AttackData attack = m_listAttacks[indexAttack];
            enemy.takeDamage(attack.damage);
			//attack.action.execute();
			
			statusBack = true;
		}
	}
	
	return statusBack;
}

void CardPokemon::takeDamage(unsigned short damage)
{
	if (damage > m_lifeLeft)
	{
		m_lifeLeft = 0;
	}
	else
	{
		m_lifeLeft -= damage;
	}
}

bool CardPokemon::canAttackFromStatus()
{
	return Status_Normal == m_status;
}

bool CardPokemon::hasEnoughEnergies(AttackData attack)
{
	bool statusBack = true;
	
	if (0 < attack.costEnergies.count())
	{
        foreach (Enum_element indexElement, attack.costEnergies.keys())
		{

            if (countEnergies(indexElement) < attack.costEnergies.value(indexElement))
				statusBack = false;
		}
	}
		
	return statusBack;
}

bool CardPokemon::hasEnoughEnergies(int indexAttack)
{
	bool statusBack = false;
	
	if ((0 <= indexAttack) && (m_listAttacks.count() > indexAttack))
	{
		statusBack = hasEnoughEnergies(m_listAttacks[indexAttack]);
	}
	
	return statusBack;
}

bool CardPokemon::isBase()
{
	return -1 == m_evolutionFrom;
}

bool CardPokemon::isSubEvolutionOf(CardPokemon* evolution)
{
    return m_id == evolution->m_evolutionFrom;
}

bool CardPokemon::isEvolutionOf(CardPokemon* evolution)
{
    return m_evolutionFrom == evolution->m_id;
}

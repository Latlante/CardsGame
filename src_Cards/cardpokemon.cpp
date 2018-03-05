#include "cardpokemon.h"
#include <QMap>

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

CardPokemon::CardPokemon(const QString &infoCsv)
{
    QStringList arguments = infoCsv.split(";");

    QList<AttackData> listAttacks;
    for(int i=0;i<3;++i)
    {
        AttackData attack;
        attack.name = arguments[InfoDb_Att1_Name];
        attack.description = arguments[InfoDb_Att1_Description];
        attack.damage = arguments[InfoDb_Att1_Damage].toInt();

        QMap<AbstractCard::Enum_element, unsigned short> listEnergies;
        for(int indexEnergies=0;indexEnergies<AbstractCard::Element_Count;++indexEnergies)
        {
            int indexEnergy = static_cast<int>(InfoDb_Att1_Element_Bug)+indexEnergies;
            QString contenuCell = arguments[indexEnergy];

            if (contenuCell != "")
            {
                listEnergies.insert(indexEnergies, contenuCell.toInt());
            }
        }
    }

    AttackData attack1;
    attack1.name = informationForLine[9];
    attack1.description = informationForLine[10];
    attack1.damage = informationForLine[11].toInt();
    cardToReturn = new CardPokemon( informationForLine[0].toInt(),
                                    informationForLine[1],
                                    static_cast<AbstractCard::Enum_element>(informationForLine[3]),
                                    informationForLine[2].toUShort(),);
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

Enum_statusOfPokemon CardPokemon::status()
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
		if (energy.element() == element)
			count++;
	}
	
	return count;
}

bool CardPokemon::tryToAttack(int indexAttack, const CardPokemon& enemy)
{
	bool statusBack = false;
	
	if ((0 > indexAttack) || (m_listAttacks.count() <= indexAttack))
		throw "CardPokemon::attack() => index incohérent (" + indexAttack + ")";
	
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
		foreach (QPair<Enum_element, unsigned short> energy, attack.costEnergies)
		{
			if (countEnergies(energy.first()) < energy.second())
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
	return m_id == evolution.m_evolutionFrom;
}

bool CardPokemon::isEvolutionOf(CardPokemon* evolution)
{
	return m_evolutionFrom == evolution.m_id;
}

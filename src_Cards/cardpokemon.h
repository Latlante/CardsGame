#ifndef CARDPOKEMON_H
#define CARDPOKEMON_H

#include "abstractcard.h"

struct AttackData
{
	QString name;
	QString description;
	unsigned short damage;
    QMap<AbstractCard::Enum_element, unsigned short> costEnergies;
	AbstractAction* action;
};

class CardPokemon : public QObject, public AbstractCard
{
	Q_OBJECT
	
public:
	enum Enum_statusOfPokemon
	{
		Status_Confused = 0,
		Status_Normal,
		Status_Paralyzed,
		Status_Poisoned,
		Status_Slept
	};

    enum Enum_InformationDatabase
    {
        InfoDb_Id = 0,
        InfoDb_Name,
        InfoDb_Life,
        InfoDb_Element,
        InfoDb_ElementSecond,
        InfoDb_Weakness,
        InfoDb_Resistance,
        InfoDb_CostRetreat,
        InfoDb_IdSubevolution,
        InfoDb_Att1_Name,
        InfoDb_Att1_Description,
        InfoDb_Att1_Damage,
        InfoDb_Att1_Element_Bug,
        InfoDb_Att1_Element_Dark,
        InfoDb_Att1_Element_Dragon,
        InfoDb_Att1_Element_Electric,
        InfoDb_Att1_Element_Fighting,
        InfoDb_Att1_Element_Fire,
        InfoDb_Att1_Element_Flying,
        InfoDb_Att1_Element_Ghost,
        InfoDb_Att1_Element_Grass,
        InfoDb_Att1_Element_Ice,
        InfoDb_Att1_Element_Normal,
        InfoDb_Att1_Element_Poison,
        InfoDb_Att1_Element_Psychic,
        InfoDb_Att1_Element_Rock,
        InfoDb_Att1_Element_Water,
        InfoDb_Att1_ActionType,
        InfoDb_Att1_ActionArgument,
        InfoDb_Att2_Name,
        InfoDb_Att2_Description,
        InfoDb_Att2_Damage,
        InfoDb_Att2_Element_Bug,
        InfoDb_Att2_Element_Dark,
        InfoDb_Att2_Element_Dragon,
        InfoDb_Att2_Element_Electric,
        InfoDb_Att2_Element_Fighting,
        InfoDb_Att2_Element_Fire,
        InfoDb_Att2_Element_Flying,
        InfoDb_Att2_Element_Ghost,
        InfoDb_Att2_Element_Grass,
        InfoDb_Att2_Element_Ice,
        InfoDb_Att2_Element_Normal,
        InfoDb_Att2_Element_Poison,
        InfoDb_Att2_Element_Psychic,
        InfoDb_Att2_Element_Rock,
        InfoDb_Att2_Element_Water,
        InfoDb_Att2_ActionType,
        InfoDb_Att2_ActionArgument,
        InfoDb_Att3_Name,
        InfoDb_Att3_Description,
        InfoDb_Att3_Damage,
        InfoDb_Att3_Element_Bug,
        InfoDb_Att3_Element_Dark,
        InfoDb_Att3_Element_Dragon,
        InfoDb_Att3_Element_Electric,
        InfoDb_Att3_Element_Fighting,
        InfoDb_Att3_Element_Fire,
        InfoDb_Att3_Element_Flying,
        InfoDb_Att3_Element_Ghost,
        InfoDb_Att3_Element_Grass,
        InfoDb_Att3_Element_Ice,
        InfoDb_Att3_Element_Normal,
        InfoDb_Att3_Element_Poison,
        InfoDb_Att3_Element_Psychic,
        InfoDb_Att3_Element_Rock,
        InfoDb_Att3_Element_Water,
        InfoDb_Att3_ActionType,
        InfoDb_Att3_ActionArgument

    }

    CardPokemon(unsigned short id, 
				const QString& name, 
				AbstractCard::Enum_element element,
				unsigned short lifeTotal,
				QList<AttackData> listAttacks,
				short evolutionFrom = -1);
    CardPokemon(const QString& infoCsv);
    ~CardPokemon();

	AbstractCard::Enum_typeOfCard type();
	unsigned short lifeTotal();
	unsigned short lifeLeft();
	Enum_statusOfPokemon status();
	QList<AttackData> listAttacks();
	
	unsigned short countEnergies();
	unsigned short countEnergies(Enum_element element);
	
	bool tryToAttack(int indexAttack, const CardPokemon& enemy);
	void takeDamage(unsigned short damage);
	bool canAttackFromStatus();
	bool hasEnoughEnergies(AttackData attack);
	bool hasEnoughEnergies(int indexAttack);
	bool isBase();
	bool isSubEvolutionOf(CardPokemon* evolution);
	bool isEvolutionOf(CardPokemon* evolution);

private:
	AbstractCard::Enum_element m_element;
	unsigned short m_lifeTotal;
	unsigned short m_lifeLeft;
	Enum_statusOfPokemon m_status;
	QList<AttackData> m_listAttacks;
	QList<CardEnergy*> m_listEnergies;
	short m_evolutionFrom;
	
};

#endif // CARDPOKEMON_H

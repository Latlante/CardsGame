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

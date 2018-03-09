#ifndef ABSTRACTACTION_H
#define ABSTRACTACTION_H

#include <QObject>

class AbstractAction
{
public:
	enum Enum_typeOfAction
	{
		Action_None = 0,
		Action_ChangeEnemyStatus = 1,
		Action_ChangeEnemyStatus_Random = 2,
        Action_RemoveEnergyAttached = 3,
        Action_Healing = 4,
        Action_ProtectedAgainstDamage = 5,
		Action_MoreDamageByEnergy = 6
    };

    AbstractAction(unsigned short id, const QString& name);
    virtual ~AbstractAction();
	
    virtual Enum_typeOfAction type() = 0;
    virtual void executeAction() = 0;

    unsigned short id();
	const QString name();
	void setName(const QString& name);

private:
	unsigned short m_id;
	QString m_name;
};

#endif // ABSTRACTACTION_H

#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include <QAbstractListModel>

class AbstractCard;

class AbstractPacket : public QAbstractListModel
{
public:
	enum Enum_roleCard
	{
		Role_name
	};

    AbstractPacket(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~AbstractPacket();
	
	static void declareQML();
	
	virtual int maxCards() = 0;
	bool addNewCard(AbstractCard* newCard);
	
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	
protected:
	QList<AbstractCard*> m_listCards;

    AbstractCard* takeACard(int index);
	QHash<int, QByteArray> roleNames() const override;


	

};

#endif // ABSTRACTPACKET_H

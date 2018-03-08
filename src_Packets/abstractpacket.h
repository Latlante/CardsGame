#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include <QAbstractListModel>

class AbstractCard;

class AbstractPacket : public QAbstractListModel
{
    Q_OBJECT
public:
	enum Enum_roleCard
	{
		Role_name
	};

    AbstractPacket(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~AbstractPacket();
	
	static void declareQML();
	
    virtual int maxCards() = 0;
    bool isFull();
    bool addNewCard(AbstractCard* newCard);
    AbstractCard* takeACard(int index);
    AbstractCard* card(int index);
    bool removeFromPacket(AbstractCard* card);
	
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:
    void countChanged(int);
	
protected:
	QList<AbstractCard*> m_listCards;


	QHash<int, QByteArray> roleNames() const override;

protected slots:
    void updateAllData();


	

};

#endif // ABSTRACTPACKET_H

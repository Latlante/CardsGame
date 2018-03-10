#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H

#include <QAbstractTableModel>

class AbstractCard;

class AbstractPacket : public QAbstractTableModel
{
    Q_OBJECT
public:
	enum Enum_roleCard
	{
        Role_name = 0,
        Role_Attack1_Name,
        Role_Attack2_Name,
        Role_Attack3_Name,
	};

    AbstractPacket(QList<AbstractCard*> listCards = QList<AbstractCard*>());
    virtual ~AbstractPacket();
	
	static void declareQML();
	
    virtual int maxCards() = 0;
    int countCard() const;
    bool isFull();
    bool addNewCard(AbstractCard* newCard);
    AbstractCard* takeACard(int index);
    AbstractCard* card(int index);
    bool removeFromPacket(AbstractCard* card);
	
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual int rowCount(const QModelIndex& index = QModelIndex()) const override;

signals:
    void countChanged(int);
	
protected:
	QList<AbstractCard*> m_listCards;


	QHash<int, QByteArray> roleNames() const override;

protected slots:
    void updateAllData();


	

};

#endif // ABSTRACTPACKET_H

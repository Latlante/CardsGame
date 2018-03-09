#include "abstractpacket.h"

#include <QDebug>
#include "src_Cards/abstractcard.h"
#include "src_Cards/cardpokemon.h"

AbstractPacket::AbstractPacket(QList<AbstractCard*> listCards) :
    QAbstractTableModel(NULL),
	m_listCards(listCards)
{
	
}

AbstractPacket::~AbstractPacket()
{
	while (0 < m_listCards.count())
	{
		AbstractCard* card = m_listCards.takeFirst();
		delete card;
	}
}
	
/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
void AbstractPacket::declareQML()
{
    //qmlRegisterUncreatableType<AbstractPacket>("com.gui", 1, 0, "FMUnfinishedTransactionListModel", "ItemType FMUnfinishedTransactionListModel cannot be created.");
}

int AbstractPacket::countCard() const
{
    return columnCount();
}

bool AbstractPacket::isFull()
{
    bool full = false;

    if ((maxCards() >= 0) && (countCard() >= maxCards()))
        full = true;

    return full;
}

bool AbstractPacket::addNewCard(AbstractCard* newCard)
{
    qDebug() << __PRETTY_FUNCTION__;
	bool statusBack = false;
	
    if ((NULL != newCard) && (!isFull()))
	{
        beginInsertRows(QModelIndex(), 0, countCard());
		m_listCards.append(newCard);
        endInsertRows();

        connect(newCard, &AbstractCard::dataChanged, this, &AbstractPacket::updateAllData);

        qDebug() << __PRETTY_FUNCTION__ << "Carte ajoutée";

        emit countChanged(countCard());
		statusBack = true;
	}
	
	return statusBack;
}

AbstractCard* AbstractPacket::takeACard(int index)
{
    AbstractCard* card = NULL;

    if ((index >= 0) && (index < countCard()))
    {
        beginRemoveRows(QModelIndex(), 0, countCard());
        card = m_listCards.takeAt(index);
        endRemoveRows();

        emit countChanged(countCard());
    }

    return card;
}

AbstractCard* AbstractPacket::card(int index)
{
    AbstractCard* card = NULL;

    if ((index >= 0) && (index < countCard()))
    {
        card = m_listCards[index];
    }

    return card;
}

bool AbstractPacket::removeFromPacket(AbstractCard *card)
{
    bool removeSuccess = false;

    if(m_listCards.indexOf(card) != -1)
    {
        beginRemoveRows(QModelIndex(), 0, countCard());
        removeSuccess = m_listCards.removeOne(card);
        endRemoveRows();

        emit countChanged(countCard());
    }

    return removeSuccess;
}

int AbstractPacket::columnCount(const QModelIndex &) const
{
    return m_listCards.count();
}

QVariant AbstractPacket::data(const QModelIndex& index, int role) const
{
    int iRow = index.row();
    if (iRow < 0 || iRow >= countCard())
    {
        qCritical() << __PRETTY_FUNCTION__ << "bad row num : " << iRow;
        return QVariant();
    }

    if ((Role_name == role) || (Qt::DisplayRole == role))
    {
        return m_listCards[index.row()]->name();
    }

    return QVariant::Invalid;
}

int AbstractPacket::rowCount(const QModelIndex& index) const
{
    int rows = 0;

    if((index.column() >= 0) && (index.column() < columnCount()))
    {
        AbstractCard* abCard = m_listCards[index.column()];

        if(abCard->type() == AbstractCard::TypeOfCard_Energy)
        {
            rows = 2;   //Nom + élément
        }
        else if(abCard->type() == AbstractCard::TypeOfCard_Pokemon)
        {
            CardPokemon* pokemon = static_cast<CardPokemon*>(abCard);
            rows = 1 /*Nom du pokemon*/ + pokemon->listAttacks().count();
        }
    }

    return rows;
}

/************************************************************
*****				FONCTIONS PROTEGEES					*****
************************************************************/
QHash<int, QByteArray> AbstractPacket::roleNames() const
{
    QHash<int, QByteArray> roles;
    /*roles[TRANSACTION_TARGET_SN] = "target";
    roles[TRANSACTION_SOURCE_SN] = "source";
    roles[TRANSACTION_NUMBER_OF_UV] = "numberUV";
    roles[TRANSACTION_STATUS] = "status";*/
    roles[Role_name] = "name";

    return roles;
}

/************************************************************
*****			FONCTIONS SLOT PROTEGEES				*****
************************************************************/
void AbstractPacket::updateAllData()
{
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

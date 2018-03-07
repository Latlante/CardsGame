#include "abstractpacket.h"

#include <QDebug>
#include "src_Cards/abstractcard.h"

AbstractPacket::AbstractPacket(QList<AbstractCard*> listCards) :
    QAbstractListModel(NULL),
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

bool AbstractPacket::isFull()
{
    bool full = false;

    if ((maxCards() >= 0) && (rowCount() >= maxCards()))
        full = true;

    return full;
}

bool AbstractPacket::addNewCard(AbstractCard* newCard)
{
    qDebug() << __PRETTY_FUNCTION__;
	bool statusBack = false;
	
    if ((NULL != newCard) && (!isFull()))
	{
		m_listCards.append(newCard);
        beginInsertRows(QModelIndex(), 0, rowCount());
        endInsertRows();

        qDebug() << __PRETTY_FUNCTION__ << "Carte ajoutée";

        emit countChanged(rowCount());
		statusBack = true;
	}
	
	return statusBack;
}

AbstractCard* AbstractPacket::takeACard(int index)
{
    AbstractCard* card = NULL;

    if ((index >= 0) && (index < rowCount()))
    {
        beginRemoveRows(QModelIndex(), 0, rowCount());
        card = m_listCards.takeAt(index);
        endRemoveRows();

        emit countChanged(rowCount());
    }

    return card;
}

AbstractCard* AbstractPacket::card(int index)
{
    AbstractCard* card = NULL;

    if ((index >= 0) && (index < rowCount()))
    {
        card = m_listCards[index];
    }

    return card;
}

int AbstractPacket::rowCount(const QModelIndex&) const
{
    return m_listCards.count();
}

QVariant AbstractPacket::data(const QModelIndex& index, int role) const
{
    //qDebug() << __PRETTY_FUNCTION__ << ", index: " << index << ", role: " << role;

    /*int iRow = index.row();
    if (iRow < 0 || iRow >= m_listUnfinishedTransaction.count())
    {
        qCritical() << __METHOD_NAME__ << "bad row num : " << iRow;
        return QVariant();
    }

    FMUnfinishedTransaction* pTransaction = m_listUnfinishedTransaction[iRow];
    if (NULL != pTransaction)
    {
        if (TRANSACTION_TARGET_SN == role)
        {
            return QString::number(pTransaction->getSerialNumberTarget());
        }
        else if (TRANSACTION_SOURCE_SN == role)
        {
            return QString::number(pTransaction->getSerialNumberSource());
        }
        else if (TRANSACTION_NUMBER_OF_UV == role)
        {
            return pTransaction->getNumberOfUV();
        }
        else if (TRANSACTION_STATUS == role)
        {
            return pTransaction->getTransactionStatusAsString();
        }
    }
    else
    {
        qCritical() << __METHOD_NAME__ << "Transaction is null.";
        return QVariant();
    }*/

    int iRow = index.row();
    if (iRow < 0 || iRow >= rowCount())
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

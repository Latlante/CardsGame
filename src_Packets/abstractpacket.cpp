#include "abstractpacket.h"
#include "src_Cards/abstractcard.h"

AbstractPacket::AbstractPacket(QList<AbstractCard*> listCards) :
	QAbstractListModel(),
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

bool AbstractPacket::addNewCard(AbstractCard* newCard)
{
	bool statusBack = false;
	
	if ((NULL != newCard) && (m_listCards.count() <= maxCards()))
	{
        beginInsertRows(QModelIndex(), 0, rowCount());
		m_listCards.append(newCard);
        endInsertRows();

		statusBack = true;
	}
	
	return statusBack;
}

int AbstractPacket::rowCount(const QModelIndex& parent) const
{
    return m_listCards.count();
}

QVariant AbstractPacket::data(const QModelIndex& index, int role) const
{
    //qDebug() << __METHOD_NAME__ << ", index: " << index << ", role: " << role;

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

    return QVariant::Invalid;
}

/************************************************************
*****				FONCTIONS PROTEGEES					*****
************************************************************/
AbstractCard* AbstractPacket::takeACard(int index)
{
    AbstractCard* card = NULL;

    if ((index >= 0) && (index < rowCount()))
    {
        beginRemoveRows(QModelIndex(), 0, rowCount());
        card = m_listCards.takeAt(index);
        endRemoveRows();
    }

    return card;
}

QHash<int, QByteArray> AbstractPacket::roleNames() const
{
    QHash<int, QByteArray> roles;
    /*roles[TRANSACTION_TARGET_SN] = "target";
    roles[TRANSACTION_SOURCE_SN] = "source";
    roles[TRANSACTION_NUMBER_OF_UV] = "numberUV";
    roles[TRANSACTION_STATUS] = "status";*/

    return roles;
}

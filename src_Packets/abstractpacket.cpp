#include "abstractpacket.h"

#include <QDebug>
#include "src_Cards/abstractcard.h"
#include "src_Cards/cardpokemon.h"
#include "src_Cards/cardenergy.h"

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
    //qDebug() << __PRETTY_FUNCTION__;
	bool statusBack = false;
	
    if ((NULL != newCard) && (!isFull()))
	{
        beginInsertColumns(QModelIndex(), 0, columnCount());
		m_listCards.append(newCard);
        endInsertColumns();

        connect(newCard, &AbstractCard::dataChanged, this, &AbstractPacket::updateAllData);

        //qDebug() << __PRETTY_FUNCTION__ << "Carte ajoutée";

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
        beginRemoveColumns(QModelIndex(), 0, columnCount());
        card = m_listCards.takeAt(index);
        endRemoveColumns();

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
        beginRemoveColumns(QModelIndex(), 0, columnCount());
        removeSuccess = m_listCards.removeOne(card);
        endRemoveColumns();

        emit countChanged(countCard());
    }

    return removeSuccess;
}

int AbstractPacket::columnCount(const QModelIndex &) const
{
    //qDebug() << __PRETTY_FUNCTION__ << m_listCards.count();
    return m_listCards.count();
}

QVariant AbstractPacket::data(const QModelIndex& index, int role) const
{
    //qDebug() << __PRETTY_FUNCTION__ << index << role;
    int iRow = index.row();
    int iColumn = index.column();
    if ((iRow < 0) || (iRow >= rowCount()) || (iColumn < 0) || (iColumn >= columnCount()))
    {
        qCritical() << __PRETTY_FUNCTION__ << "bad column num : " << iRow;
        return QVariant();
    }

    if ((Role_name == role) || (Qt::DisplayRole == role))
    {
        //return
        //return "test";
        AbstractCard* abCard = m_listCards[index.column()];

        if(index.row() == 0)
        {
            if(abCard->type() == AbstractCard::TypeOfCard_Energy)
                return "Energie";
            else
                return abCard->name();
        }
        else if(index.row() == 1)
        {
            if(abCard->type() == AbstractCard::TypeOfCard_Pokemon)
            {
                CardPokemon* pokemon = static_cast<CardPokemon*>(abCard);
                QList<AttackData> listAttacks = pokemon->listAttacks();

                if(listAttacks.count() >= 1)
                    return listAttacks[0].name;
                else
                    return "";
            }
            else if(abCard->type() == AbstractCard::TypeOfCard_Energy)
            {
                return abCard->name();
            }
        }
        else if(index.row() == 2)
        {
            if(abCard->type() == AbstractCard::TypeOfCard_Pokemon)
            {
                CardPokemon* pokemon = static_cast<CardPokemon*>(abCard);
                QList<AttackData> listAttacks = pokemon->listAttacks();

                if(listAttacks.count() >= 2)
                    return listAttacks[1].name;
                else
                    return "";
            }
        }
        else if(index.row() == 3)
        {
            if(abCard->type() == AbstractCard::TypeOfCard_Pokemon)
            {
                CardPokemon* pokemon = static_cast<CardPokemon*>(abCard);
                QList<AttackData> listAttacks = pokemon->listAttacks();

                if(listAttacks.count() >= 3)
                    return listAttacks[2].name;
                else
                    return "";
            }
        }
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

    //qDebug() << __PRETTY_FUNCTION__ << rows;

    return 4;
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

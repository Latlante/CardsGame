#include "board.h"
#include "ui_board.h"

#include <QDebug>

#include "src_Packets/bencharea.h"
#include "src_Packets/packetdeck.h"
#include "src_Packets/fightarea.h"
#include "src_Packets/packethand.h"
#include "src_Packets/packetrewards.h"
#include "src_Packets/packettrash.h"
#include "src_Cards/cardenergy.h"
#include "src_Cards/cardpokemon.h"
#include "common/database.h"

Board::Board(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Board),
    m_gameManager(new GameManager())
{
    ui->setupUi(this);

    qDebug() << "Démarrage de l'application";

    connect(ui->pushButton_StartGame, &QPushButton::clicked, this, &Board::onClicked_pushButton_StartGame);

    QString nom = "Corentin";
    QList<AbstractCard*> listCards = m_gameManager->chooseCards(nom);
    Player* playerCorentin = m_gameManager->addNewPlayer(nom, listCards);
    ui->listView_BenchArea_P1->setModel(playerCorentin->bench());
    ui->listView_FightingArea_P1->setModel(playerCorentin->fight());
    ui->listView_Hand_P1->setModel(playerCorentin->hand());
    connect(ui->listView_Hand_P1, &QListView::doubleClicked, this, &Board::onDClickedCell_Hand_P1);
    connect(playerCorentin->deck(), &PacketDeck::countChanged, this, &Board::onCountChanged_Deck_P1);
    connect(playerCorentin->rewards(), &PacketDeck::countChanged, this, &Board::onCountChanged_Rewards_P1);
    connect(playerCorentin->trash(), &PacketDeck::countChanged, this, &Board::onCountChanged_Trash_P1);

    connect(ui->pushButton_EndOfTurn_P1, &QPushButton::clicked, this, &Board::onClicked_pushButton_EndOfTurn);

    ui->label_Deck_P1->setText(QString::number(playerCorentin->deck()->rowCount()));

    m_listWidgetsByPlayer.insert(playerCorentin, ui->listView_BenchArea_P1);
    m_listWidgetsByPlayer.insert(playerCorentin, ui->listView_FightingArea_P1);
    m_listWidgetsByPlayer.insert(playerCorentin, ui->listView_Hand_P1);
    m_listWidgetsByPlayer.insert(playerCorentin, ui->pushButton_EndOfTurn_P1);


    nom = "Alice";
    listCards = m_gameManager->chooseCards(nom);
    Player* playerAlice = m_gameManager->addNewPlayer(nom, listCards);
    ui->listView_BenchArea_P2->setModel(playerAlice->bench());
    ui->listView_FightingArea_P2->setModel(playerAlice->fight());
    ui->listView_Hand_P2->setModel(playerAlice->hand());
    connect(ui->listView_Hand_P2, &QListView::doubleClicked, this, &Board::onDClickedCell_Hand_P2);
    connect(playerAlice->deck(), &PacketDeck::countChanged, this, &Board::onCountChanged_Deck_P2);
    connect(playerAlice->rewards(), &PacketDeck::countChanged, this, &Board::onCountChanged_Rewards_P2);
    connect(playerAlice->trash(), &PacketDeck::countChanged, this, &Board::onCountChanged_Trash_P2);

    connect(ui->pushButton_EndOfTurn_P2, &QPushButton::clicked, this, &Board::onClicked_pushButton_EndOfTurn);

    ui->label_Deck_P2->setText(QString::number(playerAlice->deck()->rowCount()));

    m_listWidgetsByPlayer.insert(playerAlice, ui->listView_BenchArea_P2);
    m_listWidgetsByPlayer.insert(playerAlice, ui->listView_FightingArea_P2);
    m_listWidgetsByPlayer.insert(playerAlice, ui->listView_Hand_P2);
    m_listWidgetsByPlayer.insert(playerAlice, ui->pushButton_EndOfTurn_P2);

    /*connect(playerCorentin->bench(), &BenchArea::countChanged, this, &Board::onCountChanged_Packets);
    connect(playerCorentin->fight(), &BenchArea::countChanged, this, &Board::onCountChanged_Packets);
    connect(playerCorentin->hand(), &BenchArea::countChanged, this, &Board::onCountChanged_Packets);
    connect(playerAlice->bench(), &BenchArea::countChanged, this, &Board::onCountChanged_Packets);
    connect(playerAlice->fight(), &BenchArea::countChanged, this, &Board::onCountChanged_Packets);
    connect(playerAlice->hand(), &BenchArea::countChanged, this, &Board::onCountChanged_Packets);*/

}

Board::~Board()
{
    delete ui;
    delete m_gameManager;
}

/************************************************************
*****			  FONCTIONS SLOTS PRIVEES				*****
************************************************************/
void Board::onCountChanged_Deck_P1(int count)
{
    ui->label_Deck_P1->setText(QString::number(count));
}

void Board::onCountChanged_Rewards_P1(int count)
{
    ui->label_Rewards_P1->setText(QString::number(count));
}

void Board::onCountChanged_Trash_P1(int count)
{
    ui->label_Trash_P1->setText(QString::number(count));
}

void Board::onCountChanged_Deck_P2(int count)
{
    ui->label_Deck_P2->setText(QString::number(count));
}

void Board::onCountChanged_Rewards_P2(int count)
{
    ui->label_Rewards_P2->setText(QString::number(count));
}

void Board::onCountChanged_Trash_P2(int count)
{
    ui->label_Trash_P2->setText(QString::number(count));
}

void Board::onDClickedCell_Hand_P1(const QModelIndex &index)
{
    qDebug() << __PRETTY_FUNCTION__ << ", double clicked on:" << index;

    Player* play = findPlayerByWidget(ui->listView_Hand_P1);

    if (play != NULL)
    {
        if(play->moveCardFromHandToBench(index) == false)
        {
            qDebug() << __PRETTY_FUNCTION__ << ", problème lors du transfert de hand vers bench";
        }
    }

}

void Board::onDClickedCell_Hand_P2(const QModelIndex &index)
{
    qDebug() << __PRETTY_FUNCTION__ << ", double clicked on:" << index;

    Player* play = findPlayerByWidget(ui->listView_Hand_P2);

    if (play != NULL)
    {
        if(play->moveCardFromHandToBench(index) == false)
        {
            qDebug() << __PRETTY_FUNCTION__ << ", problème lors du transfert de hand vers bench";
        }
    }
}

void Board::onClicked_pushButton_EndOfTurn()
{
    m_gameManager->currentPlayer()->skipYourTurn();
}

/*void Board::onCountChanged_Packets(int count)
{
    qDebug() << "Packet count changed:" << count;
}*/

void Board::onClicked_pushButton_StartGame()
{
    m_gameManager->drawFirstCards(4);
    m_gameManager->startGame();
}

/************************************************************
*****               FONCTIONS PRIVEES                   *****
************************************************************/
Player* Board::findPlayerByWidget(QWidget *wid)
{
    Player* playerToReturn = NULL;

    foreach(Player *play, m_listWidgetsByPlayer.keys())
    {
        if(m_listWidgetsByPlayer.contains(play, wid))
        {
            playerToReturn = play;
            break;
        }
    }

    return playerToReturn;
}

#include "gamemanager.h"
#include "src_Cards/abstractcard.h"

#include "dlgselectcards.h"
#include "utils.h"

GameManager::GameManager(QObject *parent) :
	QObject(parent),
	m_listPlayers(QList<Player*>()),
	m_indexCurrentPlayer(0),
	m_gameIsReady(false)
{
	
}

GameManager::~GameManager()
{
	
}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
void GameManager::initGame()
{
	//Création de 2 joueurs pour le moment
	QStringList listNames = QStringList() << "Corentin" << "Alice";
	
	for(int i=0;i<listNames.count();++i)
	{
		//Création du deck
		QList<AbstractCard*> listCards = chooseCards(listNames[i]);
		
		//Création du nouveau joueur
		addNewPlayer(listNames[i], listCards);
		
		//Distribution de la première main
        //drawFirstCards(6);
	}
	
	//On choisit le joueur qui va jouer en premier
	selectFirstPlayer();
}

QList<AbstractCard*> GameManager::chooseCards(const QString& name)
{
	//Connecter à la fenêtre de sélection
    QList<AbstractCard*> listCards;
    DlgSelectCards *fen = new DlgSelectCards(name);
#ifdef MODE_TEST
    listCards = fen->listOfRandomCards();
#else
    fen->exec();
    listCards = fen->listOfSelectedCards();
#endif

    delete fen;

    return listCards;
}

Player *GameManager::addNewPlayer(QString name, QList<AbstractCard*> listCards)
{
	Player* newPlayer = new Player(name, listCards);
	m_listPlayers.append(newPlayer);

    return newPlayer;
}

void GameManager::startGame()
{
	
}

void GameManager::drawFirstCards(int count)
{
    foreach(Player *play, m_listPlayers)
    {
        for(int i=0;i<count;++i)
        {
            play->drawOneCard();
        }
    }

}

int GameManager::selectFirstPlayer()
{
    m_indexCurrentPlayer = Utils::selectFirstPlayer(m_listPlayers.count());
    return m_indexCurrentPlayer;
}

void GameManager::nextPlayer()
{
	endOfTurn();
	
	m_indexCurrentPlayer++;
	if (m_listPlayers.count() <= m_indexCurrentPlayer)
		m_indexCurrentPlayer = 0;
		
	m_listPlayers[m_indexCurrentPlayer]->newTurn();
}

void GameManager::endOfTurn()
{
	foreach(Player* play, m_listPlayers)
	{
		play->blockPlayer();
	}
}

bool GameManager::gameIsFinished()
{
	bool hasAWinner = false;
	
	foreach(Player* play, m_listPlayers)
	{
		hasAWinner |= play->isWinner();
	}
	
	return hasAWinner;
}

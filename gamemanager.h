#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include "player.h"

class AbstractCard;

class GameManager : public QObject
{
	Q_OBJECT
	
public:
	GameManager(QObject *parent = NULL);
	~GameManager();
	
	void initGame();
	QList<AbstractCard*> chooseCards(const QString& name);
    Player* addNewPlayer(QString name, QList<AbstractCard*> listCards);
	void startGame();
    void drawFirstCards(int count);
	int selectFirstPlayer();
	void nextPlayer();
	void endOfTurn();
	bool gameIsFinished();

private:
	QList<Player*> m_listPlayers;
	unsigned short m_indexCurrentPlayer;
	
	bool m_gameIsReady;


};

#endif // GAMEMANAGER_H

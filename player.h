#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
	Q_OBJECT
	
public:
	Player(QString name, QList<AbstractCard*> listCards, QObject *parent = NULL);
	~Player();
	
	PacketDeck* deck();
	PacketRewards* rewards();
	PacketHand* hand();
	BenchArea* bench();
	FightArea* fight();
	
	void init(QList<AbstractCard*> listCards);
	void newTurn();
	void blockPlayer();
	void drawOneCard();
	bool isWinner();


private:
	QString m_name;
	PacketDeck* m_deck;
	PacketRewards* m_rewards;
	PacketHand* m_hand;
	BenchArea* m_bench;
	FightArea* m_fight;


};

#endif // PLAYER_H

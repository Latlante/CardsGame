#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class AbstractCard;
class PacketDeck;
class PacketRewards;
class PacketHand;
class BenchArea;
class FightArea;
class PacketTrash;

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
    PacketTrash* trash();
	
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
    PacketTrash* m_trash;


};

#endif // PLAYER_H

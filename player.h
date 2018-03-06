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
	
    BenchArea* bench();
	PacketDeck* deck();
    FightArea* fight();
	PacketHand* hand();
    PacketRewards* rewards();
    PacketTrash* trash();
	
	void init(QList<AbstractCard*> listCards);
	void newTurn();
	void blockPlayer();
	void drawOneCard();
	bool isWinner();


private:
	QString m_name;
    BenchArea* m_bench;
	PacketDeck* m_deck;
    FightArea* m_fight;
    PacketHand* m_hand;
	PacketRewards* m_rewards;
    PacketTrash* m_trash;


};

#endif // PLAYER_H

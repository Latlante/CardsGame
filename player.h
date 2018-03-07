#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class AbstractCard;
class CardAction;
class CardEnergy;
class CardPokemon;
class AbstractPacket;
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
    void skipYourTurn();
	void blockPlayer();
    bool isPlaying();
	void drawOneCard();
    void attack();
	bool isWinner();

    bool moveCardFromHandToBench(const QModelIndex& index);
    bool moveCardFromBenchToFight(const QModelIndex& index);
    bool moveCardFromFightToTrash(const QModelIndex& index);


signals:
    void endOfTurn();

private:
	QString m_name;
    bool m_canPlay;

    BenchArea* m_bench;
	PacketDeck* m_deck;
    FightArea* m_fight;
    PacketHand* m_hand;
	PacketRewards* m_rewards;
    PacketTrash* m_trash;

    bool moveCardFromPacketToAnother(AbstractPacket* source, AbstractPacket* destination, int index);

};

#endif // PLAYER_H

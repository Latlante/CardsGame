#ifndef UTILS_H
#define UTILS_H

#include <QObject>

#include "src_Cards/cardenergy.h"
#include "src_Cards/cardpokemon.h"

class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = nullptr);

    static AbstractCard* cardById(unsigned short id);

    static unsigned short selectFirstPlayer(int count);

private:
    static int randomValue(int min, int max);
};

#endif // UTILS_H

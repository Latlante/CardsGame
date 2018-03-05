#include "utils.h"

#include <QFile>

Utils::Utils(QObject *parent) : QObject(parent)
{

}

AbstractCard* Utils::cardById(unsigned short id)
{

}

unsigned short Utils::selectFirstPlayer(int count)
{
    return static_cast<short>(randomValue(0, count));
}

int Utils::randomValue(int min, int max)
{
    return (qrand() %(max - min + 1)) + min;
}

#include "utils.h"

#include <QFile>

Utils::Utils(QObject *parent) : QObject(parent)
{

}

AbstractCard* Utils::cardById(unsigned short id)
{
    AbstractCard* cardToReturn = NULL;
    QFile fichier("database/db.csv");
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);

    QString contenuGeneral = fichier.readAll();
    QStringList contenuParLigne = contenuGeneral.split("\n");

    int indexLine = -1;
    for(int i=0;i<contenuParLigne.count();++i)
    //foreach(QString ligne, contenuParLigne)
    {
        int idCard = contenuParLigne[i].section(";", 0, 0).toInt();

        if (idCard == id)
        {
            indexLine = i;
            break;
        }
    }

    if (indexLine >= 0)
    {
        QStringList informationForLine = contenuParLigne[indexLine].split(";");

        if ((indexLine >= 0) && (indexLine < 1000))
        {
            AttackData attack1;
            attack1.name = informationForLine[9];
            attack1.description = informationForLine[10];
            attack1.damage = informationForLine[11].toInt();
            cardToReturn = new CardPokemon( informationForLine[0].toInt(),
                                            informationForLine[1],
                                            static_cast<AbstractCard::Enum_element>(informationForLine[3]),
                                            informationForLine[2].toUShort(),);
            QString texte;
            texte.toUShort();
        }
    }

    return cardToReturn;
}

unsigned short Utils::selectFirstPlayer(int count)
{
    return static_cast<short>(randomValue(0, count));
}

int Utils::randomValue(int min, int max)
{
    return (qrand() %(max - min + 1)) + min;
}

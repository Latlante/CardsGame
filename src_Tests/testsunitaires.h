#ifndef TESTSUNITAIRES_H
#define TESTSUNITAIRES_H

#include <QObject>
#include <QDebug>

class TestsUnitaires : public QObject
{
    Q_OBJECT
public:
    explicit TestsUnitaires(QObject *parent = nullptr);

signals:

private:
    template<typename T> void COMPARE(T arg1, T arg2);

    void checkStructCardPokemonByCreatingACustomOne();
    void checkStructCardPokemonByCreatingASpecificOne();
    void checkStructCardEnergyByCreatingACustomOne();
    void checkStructCardEnergyByCreatingASpecificOne();
};

#endif // TESTSUNITAIRES_H

#include "abstractaction.h"

AbstractAction::AbstractAction(unsigned short id, const QString &name)
{

}

AbstractAction::~AbstractAction()
{

}

/************************************************************
*****				FONCTIONS PUBLIQUES					*****
************************************************************/
unsigned short AbstractAction::id()
{
    return m_id;
}

const QString AbstractAction::name()
{
    return m_name;
}

void AbstractAction::setName(const QString &name)
{
    m_name = name;
}

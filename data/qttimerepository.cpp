#include "qttimerepository.h"

QtTimeRepository::QtTimeRepository(QObject *parent) : QObject(parent)
{
    m_timer.start();
}

uint64_t QtTimeRepository::elapsedTime()
{
    return m_timer.nsecsElapsed();
}

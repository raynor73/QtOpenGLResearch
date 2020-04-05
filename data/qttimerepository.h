#ifndef QTTIMEREPOSITORY_H
#define QTTIMEREPOSITORY_H

#include <QObject>
#include <QElapsedTimer>
#include "domain/timerepository.h"

class QtTimeRepository : public QObject, public TimeRepository
{
    Q_OBJECT

public:
    explicit QtTimeRepository(QObject* parent);

    virtual uint64_t elapsedTime() override;

private:
    QElapsedTimer m_timer;
};

#endif // QTTIMEREPOSITORY_H

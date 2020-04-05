#ifndef TIMEREPOSITORY_H
#define TIMEREPOSITORY_H

#include <cstdint>

class TimeRepository
{
public:
    TimeRepository();
    virtual ~TimeRepository();

    virtual uint64_t elapsedTime() = 0;
};

#endif // TIMEREPOSITORY_H

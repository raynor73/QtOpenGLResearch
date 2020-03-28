#ifndef QTDISPLAYMETRICSREPOSITORY_H
#define QTDISPLAYMETRICSREPOSITORY_H

#include "domain/displaymetricsrepository.h"

class QtDisplayMetricsRepository : public DisplayMetricsRepository
{
public:
    QtDisplayMetricsRepository();
    virtual float pixelDensityFactor() const override;
    virtual int width() const override;
    virtual int height() const override;
};

#endif // QTDISPLAYMETRICSREPOSITORY_H

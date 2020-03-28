#ifndef DISPLAYMETRICS_H
#define DISPLAYMETRICS_H

class DisplayMetricsRepository
{
public:
    virtual float pixelDensityFactor() const = 0;
    virtual int width() const = 0;
    virtual int height() const = 0;
    virtual ~DisplayMetricsRepository();
};

#endif // DISPLAYMETRICS_H

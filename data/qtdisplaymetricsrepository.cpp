#include "qtdisplaymetricsrepository.h"

QtDisplayMetricsRepository::QtDisplayMetricsRepository() {}

float QtDisplayMetricsRepository::pixelDensityFactor() const {
    return 1;
}

int QtDisplayMetricsRepository::width() const {
    return 1024;
}

int QtDisplayMetricsRepository::height() const {
    return 768;
}

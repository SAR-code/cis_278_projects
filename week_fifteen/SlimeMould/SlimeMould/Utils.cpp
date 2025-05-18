#include "Utils.h"
#include <cstdlib>

double Utils::randDouble(double min, double max) {
    return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}
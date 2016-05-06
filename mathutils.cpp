#include "mathutils.h"

namespace MathUtils {

double exponentialFilter(double curVal, double prevVal, double alpha) {
    return prevVal + alpha * (curVal - prevVal);
}

}

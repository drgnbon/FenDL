#include "FenDL/ActivateFunctions/SELU.hxx"
double SELU::getActivateValue(double value) {
    if (value >= 0)
        return value * 1.0507;
    return (1.67326 * (exp(value) - 1)) * 1.0507;
}

double SELU::getDerivateValue(double value){
    if (value >= 0)
        return 1.0507;
    return (1.67326 * exp(value)) * 1.0507;
}

SELU::SELU(){};
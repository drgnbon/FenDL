#include "FenDL/ActivateFunctions/ELU.hxx"
double ELU::getActivateValue(double value) {
    if (value >= 0)
        return 1;
    return 1 * (exp(value) - 1);
}

double ELU::getDerivateValue(double value){
    if (value >= 0)
        return 1;
    return getActivateValue(value) + 1;
}

ELU::ELU(){};
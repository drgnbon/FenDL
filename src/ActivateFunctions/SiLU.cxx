#include "FenDL/ActivateFunctions/SiLU.hxx"
double SiLU::getActivateValue(double value) {
    return value * (1.0 / (1.0 + exp(-value) ));
}
double SiLU::getDerivateValue(double value){
    return getActivateValue(value) + (1.0 / (1.0 + exp(-value) )) * (1 - getActivateValue(value));
}

SiLU::SiLU(){};



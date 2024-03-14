#include "FenDL/ActivateFunctions/SoftPlus.hxx"
double SoftPlus::getActivateValue(double value) {
    return log(1+exp(value));
}

double SoftPlus::getDerivateValue(double value){
    return 1/(1+exp(-value));
}

SoftPlus::SoftPlus(){};
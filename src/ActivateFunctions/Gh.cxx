#include "FenDL/ActivateFunctions/Gh.hxx"
double Gh::getActivateValue(double value) {
    return exp(-(value*value));
}

double Gh::getDerivateValue(double value){
    return -2*value* exp(-(value*value));
}

Gh::Gh(){};
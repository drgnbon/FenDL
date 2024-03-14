#include "FenDL/ActivateFunctions/Sin.hxx"
double Sin::getActivateValue(double value) {
    return sin(value);
}

double Sin::getDerivateValue(double value){
    return cos(value);
}

Sin::Sin(){};
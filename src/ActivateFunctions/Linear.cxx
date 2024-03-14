#include "FenDL/ActivateFunctions/Linear.hxx"
double Linear::getActivateValue(double value) {
    return value;
}

double Linear::getDerivateValue(double value){
    return 1;
}

Linear::Linear(){};
#include "FenDL/ActivateFunctions/Arctg.hxx"
double Arctg::getActivateValue(double value) {
    return atan(value);
}

double Arctg::getDerivateValue(double value){
    return 1/((value*value)+1);
}

Arctg::Arctg(){};
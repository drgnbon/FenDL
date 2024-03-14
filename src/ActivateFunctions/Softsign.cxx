#include "FenDL/ActivateFunctions/Softsign.hxx"
double Softsign::getActivateValue(double value) {
    return value/(1+abs(value));
}

double Softsign::getDerivateValue(double value){
    return 1/pow(1+abs(value),2);
}

Softsign::Softsign(){};
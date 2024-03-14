#include "FenDL/ActivateFunctions/ISRU.hxx"
double ISRU::getActivateValue(double value) {
    return value/ sqrt(1+1*pow(value,2));
}

double ISRU::getDerivateValue(double value){
    return pow(1/ sqrt(1+1*pow(value,2)),3);
}

ISRU::ISRU(){};
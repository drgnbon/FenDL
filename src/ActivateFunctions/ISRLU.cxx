#include "FenDL/ActivateFunctions/ISRLU.hxx"
double ISRLU::getActivateValue(double value) {
    if(value >= 0)
        return  value;
    return value/ sqrt(1+1*(value*value));
}

double ISRLU::getDerivateValue(double value){
    if(value >= 0)
        return 1;
    return pow((1/(sqrt(1+1*pow(value,2)))),3);
}

ISRLU::ISRLU(){};
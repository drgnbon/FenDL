#include "FenDL/ActivateFunctions/LReLU.hxx"
double LReLU::getActivateValue(double value) {
    if(value >= 0)
        return value;
    return value * 0.01;
}

double LReLU::getDerivateValue(double value){
    if(value >= 0)
        return 1;
    return 0.01;
}

LReLU::LReLU(){};
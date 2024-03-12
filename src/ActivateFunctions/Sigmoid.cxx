#include "FenDL/ActivateFunctions/Sigmoid.hxx"
#include <iostream>

double Sigmoid::getActivateValue(double value) {
    return 1.0 / (1.0 + exp(-value));
}

double Sigmoid::getDerivateValue(double value){
	return getActivateValue(value)/(1 - getActivateValue(value));
}

Sigmoid::Sigmoid(){};

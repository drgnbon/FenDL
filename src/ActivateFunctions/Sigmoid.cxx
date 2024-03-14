#include "FenDL/ActivateFunctions/Sigmoid.hxx"

double Sigmoid::getActivateValue(double value) {
    return 1.0 / (1.0 + exp(-value) );
}

double Sigmoid::getDerivateValue(double value){
	return (1.0 / (1.0 + exp(-value) ))*(1 - (1.0 / (1.0 + exp(-value) )));
}

Sigmoid::Sigmoid(){};

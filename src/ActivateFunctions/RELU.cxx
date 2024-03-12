#include "FenDL/ActivateFunctions/RELU.hxx"
#include <iostream>

double RELU::getActivateValue(double value) {
	return fmax(0,value);
}

double RELU::getDerivateValue(double value){
	if(value < 0) return 0;
	return 1;
}

RELU::RELU(){};
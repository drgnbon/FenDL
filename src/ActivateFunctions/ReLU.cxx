#include "FenDL/ActivateFunctions/ReLU.hxx"

double ReLU::getActivateValue(double value) {
	return fmax(0,value);
}

double ReLU::getDerivateValue(double value){
	if(value < 0) return 0;
	return 1;
}

ReLU::ReLU(){};
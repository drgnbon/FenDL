#include "FenDL/ActivateFunctions/Th.hxx"

double Th::getActivateValue(double value) {

	return  ( exp(value) - exp(-value) ) / (exp(value) + exp(-value) )  ;
}

double Th::getDerivateValue(double value){
	return 1 - getActivateValue(value)*getActivateValue(value);
}


Th::Th(){};
#include "FenDL/ActivateFunctions/Thangh.hxx"

double Thangh::getActivateValue(double value) {

	return  ( exp(value) - exp(-value) ) / (exp(value) + exp(-value) )  ;
}

double Thangh::getDerivateValue(double value){
	return 1 - getActivateValue(value)*getActivateValue(value);
}


Thangh::Thangh(){};
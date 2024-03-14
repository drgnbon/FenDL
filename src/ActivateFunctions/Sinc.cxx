#include "FenDL/ActivateFunctions/Sinc.hxx"
double Sinc::getActivateValue(double value) {
    if(value == 0)
        return 1;
    return sin(value)/value;

}

double Sinc::getDerivateValue(double value){
    if(value == 0)
        return 0;
    return (cos(value)/value)-(sin(value)/pow(value,2));
}

Sinc::Sinc(){};
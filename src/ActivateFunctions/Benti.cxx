#include "FenDL/ActivateFunctions/Benti.hxx"

double Benti::getActivateValue(double value) {
    return ((sqrt((value * value) + 1) - 1) / 2) + value;
}

double Benti::getDerivateValue(double value) {
    return 1.0; // Значение производной для тождественной функции всегда равно 1
}

Benti::Benti() {}

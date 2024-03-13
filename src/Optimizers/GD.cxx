#include "FenDL/Optimizers/GD.hxx"

void GD::updateWeights(Matrixd &weights, Matrixd& gradient, double ls) {
    weights -= ls*gradient;
}

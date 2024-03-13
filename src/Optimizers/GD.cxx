#include "FenDL/Optimizers/GD.hxx"

void GD::updateWeights(Matrixd& weights,Matrixd& gradient,double ls,double epoch) {
    weights -= ls*gradient;
}

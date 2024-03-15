#include "FenDL/Optimizers/GD.hxx"

void GD::updateWeights(Matrixd& weights,Matrixd& gradient,int number_of_layer,double ls,double epoch) {
    weights -= ls*gradient;
}

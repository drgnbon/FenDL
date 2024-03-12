#include "FenDL/Optimizers/GD.hxx"

void GD::updateWeights(Eigen::MatrixXd &weights, Eigen::MatrixXd gradient, double ls) {
    weights -= ls*gradient;
}

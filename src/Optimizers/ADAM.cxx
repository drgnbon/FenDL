#include "FenDL/Optimizers/ADAM.hxx"

void ADAM::updateWeights(Matrixd &weights, Matrixd& gradient, double ls,int epoch) {
    Matrixd speed = weights;
    Matrixd moment = weights;
    Matrixd speed_m = weights;
    Matrixd moment_m = weights;
    speed = (0.5 * speed) + (1 - 0.5) * gradient;
    moment = (_alfa * moment) + Eigen::MatrixXd((1 - _alfa) * gradient.array().pow(2));
    speed_m = speed / (1 - pow(_gamma, epoch + 1));
    moment_m =  moment / (1 - pow(_alfa, epoch + 1));
    weights -= ls * Eigen::MatrixXd(speed_m.array().cwiseQuotient(moment_m.array().sqrt() + _epsilon).array());
}
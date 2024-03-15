#include "FenDL/Optimizers/ADAM.hxx"
#include <iostream>
void ADAM::updateWeights(Matrixd& weights,Matrixd& gradient,int number_of_layer,double ls,double epoch) {



    Matrixd& speed = _history_speed[number_of_layer];
    Matrixd& moment = _history_moment[number_of_layer];

    if (speed.size() == 0 || moment.size() == 0) {
        moment.resize(weights.rows(), weights.cols());
        speed.resize(weights.rows(), weights.cols());
        moment.setZero();
        speed.setZero();
    }


    speed = (_gamma * speed) + (1 - _gamma) * gradient;
    moment = (_alfa * moment) + Eigen::MatrixXd((1 - _alfa) * gradient.array().pow(2));

    weights -= ls * Eigen::MatrixXd((speed / (1 - pow(_gamma, epoch + 1))).array().cwiseQuotient((moment / (1 - pow(_alfa, epoch + 1))).array().sqrt() + _epsilon).array());

}

#include "FenDL/Optimizers/ADAM.hxx"
#include <iostream>
void ADAM::updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,double learning_speed = 0.5,double epoch = 1) {
    for(int i = 0;i <  _network._layers.size()-1;i++)
    {
        _history_speed[i] = (_gamma * _history_speed[i]) + (1 - _gamma) * _network._layers[i]->_gradient;
        _history_moment[i]= (_alfa * _history_moment[i]) + Eigen::MatrixXd((1 - _alfa) * _network._layers[i]->_gradient.array().pow(2));
        _network._layers[i]->_weights -= learning_speed * Eigen::MatrixXd((_history_speed[i] / (1 - pow(_gamma, epoch + 1))).array().cwiseQuotient((_history_moment[i] / (1 - pow(_alfa, epoch + 1))).array().sqrt() + _epsilon).array());
    }
}

ADAM::ADAM(NeuralNetwork &network) : Optimizer(network)
{
    _history_speed = new Matrixd[network._layers.size()];
    _history_moment = new Matrixd[network._layers.size()];
    _gamma = 0.9;
    _alfa =  0.999;
    _epsilon = 1e-8;

    for(int i  =0;i < network._layers.size();++i)
    {
        _history_speed[i] = network._layers[i]->_weights;
        _history_moment[i] = network._layers[i]->_weights;
        _history_speed[i].setZero();
        _history_moment[i].setZero();
    }

}

ADAM::~ADAM() {
    delete[] _history_speed;
    delete[] _history_moment;
}


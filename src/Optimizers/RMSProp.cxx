#include "FenDL/Optimizers/RMSProp.hxx"

RMSProp::RMSProp(NeuralNetwork &network) : Optimizer(network)
{
    _epsilon = 1e-8;
    _gamma = 0.9;
    _squared_gradient = new Matrixd[network._layers.size()];
    for(int i  =0;i < network._layers.size();++i)
    {
        _squared_gradient[i] = network._layers[i]->_weights;
        _squared_gradient[i].setZero();
    }
}

RMSProp::~RMSProp() {
    delete[] _squared_gradient;
}

void RMSProp::updateWeights(Matrixd answer, std::shared_ptr<LossFunction> _loss_function, double learning_speed,double epoch)
{
    for(int i = 0;i < _network._layers.size();++i)
    {
        _squared_gradient[i] = _gamma * _squared_gradient[i].array()  +  (1 - _gamma) * _network._layers[i]->_gradient.array().square();

        _network._layers[i]->_weights -= Matrixd ((_network._layers[i]->_gradient*learning_speed).array() / sqrt(_squared_gradient[i].array() +_epsilon));
    }
}

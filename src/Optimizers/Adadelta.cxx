#include "FenDL/Optimizers/Adadelta.hxx"

Adadelta::Adadelta(NeuralNetwork &network) : Optimizer(network)
{
    _gamma = 0.9;
    _epsilon = 1e-8;
    _squared_gradient = new Matrixd[network._layers.size()];
    _squared_updates = new Matrixd[network._layers.size()];
    for(int i  =0;i < network._layers.size();++i)
    {
        _squared_updates[i] = network._layers[i]->_weights;
        _squared_gradient[i] = network._layers[i]->_weights;
        _squared_updates[i].setZero();
        _squared_gradient[i].setZero();
    }
}

void Adadelta::updateWeights(Matrixd answer, std::shared_ptr <LossFunction> _loss_function, double learning_speed,double epoch)
{
    for(int i = 0; i < _network._layers.size(); ++i)
    {
        _squared_gradient[i] = _gamma * _squared_gradient[i].array() + (1 - _gamma) * _network._layers[i]->_gradient.array().square();

        Matrixd delta = ((_squared_updates[i].array() + _epsilon).sqrt() / (_squared_gradient[i].array() + _epsilon).sqrt()) * _network._layers[i]->_gradient.array();

        _squared_updates[i] = _gamma * _squared_updates[i].array() + (1 - _gamma) * delta.array().square();

        _network._layers[i]->_weights -= delta;
    }
}

Adadelta::~Adadelta()
{
    delete[] _squared_gradient;
    delete[] _squared_updates;
}

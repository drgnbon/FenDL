#include "FenDL/Optimizers/Adagrad.hxx"

Adagrad::Adagrad(NeuralNetwork &network) : Optimizer(network)
{
    _epsilon = 1e-8;
    _squared_gradient = new Matrixd[network._layers.size()];
    for(int i  =0;i < network._layers.size();++i)
    {
        _squared_gradient[i] = network._layers[i]->_weights;
        _squared_gradient[i].setZero();
    }
}

Adagrad::~Adagrad() {
    delete[] _squared_gradient;
}


void Adagrad::updateWeights(Matrixd answer, std::shared_ptr<LossFunction> _loss_function, double learning_speed,double epoch)
{
    for(int i = 0;i < _network._layers.size();++i)
    {
        _squared_gradient[i] =_squared_gradient[i].array() +  _network._layers[i]->_gradient.array().square();
        _network._layers[i]->_weights-= Matrixd ((learning_speed * _network._layers[i]->_gradient).array() / sqrt(_squared_gradient[i].array() + _epsilon).array()) ;
    }
}


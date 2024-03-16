#include "FenDL/Optimizers/Adadelta.hxx"

Adadelta::Adadelta(NeuralNetwork &network) : Optimizer(network)
{
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
    for(int i = 0;i < _network._layers.size();++i)
    {

        _squared_gradient[i] =_network._layers[i]->_gradient.array().square();


        if(epoch == 0) {
            _squared_updates[i] = _squared_gradient[i];
        } else {
            _squared_updates[i] = _beta * _squared_updates[i] + (1 - _beta) * _squared_gradient[i];
        }



        _network._layers[i]->_weights -= Matrixd((sqrt(_squared_gradient[i].array()+_epsilon).array() * _network._layers[i]->_gradient.array()).array()/
                                                 sqrt(_squared_updates[i].array()+_epsilon).array());


    }


}

Adadelta::~Adadelta()
{
    delete[] _squared_gradient;
    delete[] _squared_updates;

}

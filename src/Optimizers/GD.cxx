#include "FenDL/Optimizers/GD.hxx"

void GD::updateWeights(double learning_speed = 0.5,double epoch = 1) {

    for(int i = 0;i <  _network._layers.size()-1;i++){
        _network._layers[i]->_weights -= _network._layers[i]->_gradient*learning_speed;
    }
}

GD::GD(NeuralNetwork &network) : Optimizer(network){


}



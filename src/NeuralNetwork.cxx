#include "FenDL/NeuralNetwork.hxx"

NeuralNetwork::NeuralNetwork()
{
    _current_activation_function = std::make_shared<Sigmoid>();
    _current_loss_function = std::make_shared<SquareError>();
}

NeuralNetwork::~NeuralNetwork()= default;

void NeuralNetwork::setActivationFunction(std::shared_ptr<ActivationFunction> selected_activation_function)
{
    _current_activation_function = std::move(selected_activation_function);
}
void NeuralNetwork::setLossFunction(std::shared_ptr<LossFunction> selected_loss_function)
{
    _current_loss_function = std::move(selected_loss_function);
}


void NeuralNetwork::deleteAllLayers()
{
    _layers.clear();
}

void NeuralNetwork::setInputLayer(Matrixd input)
{
    _layers[0]->_active_values = input;
}

void NeuralNetwork::forwardPropogation()
{
    for(long long i = 1;i < _layers.size();++i)
    {
        _layers[i]->activateLayer(_current_activation_function,_layers[i-1]->_active_values,_layers[i-1]->_weights);
    }
}

Matrixd NeuralNetwork::predict(Matrixd input){
    _layers[0]->_active_values = input;
    forwardPropogation();
    return _layers[_layers.size()-1]->_active_values;
}





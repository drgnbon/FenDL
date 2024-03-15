#include "FenDL/NeuralNetwork.hxx"

NeuralNetwork::NeuralNetwork()
{
    _current_activation_function = std::make_shared<Sigmoid>();
}

NeuralNetwork::~NeuralNetwork()= default;

void NeuralNetwork::addComplete() const
{
    if (_layers.size() < 2) return;
    for(int i = 0;i < _layers.size()-1;++i)
        _layers[i]->buildWeightsForLayer(_layers[i+1]->_size_of_input);
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

Matrixd NeuralNetwork::predict(Matrixd& input){
    _layers[0]->_active_values = input;
    forwardPropogation();
    return _layers[_layers.size()-1]->_active_values;
}





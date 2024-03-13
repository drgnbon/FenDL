#include "FenDL/NeuralNetwork.hxx"

NeuralNetwork::NeuralNetwork()
{
    _current_activation_function = std::make_shared<Sigmoid>();
    _current_loss_function = std::make_shared<SquareError>();
    _current_optimizer = std::make_shared<GD>();
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
void NeuralNetwork::setOptimizer(std::shared_ptr<Optimizer> selected_optimizer)
{
    _current_optimizer = std::move(selected_optimizer);
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

void NeuralNetwork::backPropogation(Matrixd& right_answer)
{
    _layers[_layers.size()-1]->_derivation_neurons = _current_loss_function->getDerivationLoss(_layers[_layers.size()-1]->_active_values, right_answer);

    for(long long i = _layers.size()-2; i >= 0; --i)
    {
        _layers[i]->calculateDerivation(_layers[i]->_weights, _layers[i+1]->_derivation_neurons, _layers[i+1]->_values, _layers[i]->_active_values, _current_activation_function);
    }
}

Matrixd NeuralNetwork::predict(Matrixd input){
    _layers[0]->_active_values = input;
    forwardPropogation();
    return _layers[_layers.size()-1]->_active_values;
}

void NeuralNetwork::learn(Matrixd input,Matrixd right_answer,double learning_speed){
    _layers[0]->_active_values = input;
    forwardPropogation();
    backPropogation(right_answer);
    for(int i = 0;i < _layers.size()-1;i++){
        //_current_optimizer->updateWeights(_layers[i]->_weights,_layers[i]->_gradient,learning_speed);
        _layers[i]->_weights -= learning_speed*_layers[i]->_gradient;
    }
}




#include "FenDL/TrainerStrategy.hxx"






void TrainerStrategy::backPropogation( Matrixd right_answer){
    _network._layers[_network._layers.size()-1]->_derivation_neurons = _loss_function->getDerivationLoss(_network._layers[_network._layers.size()-1]->_active_values, right_answer);

    for(long long i = _network._layers.size()-2; i >= 0; --i)
    {
        _network._layers[i]->calculateDerivation(_network._layers[i]->_weights, _network._layers[i+1]->_derivation_neurons, _network._layers[i+1]->_values, _network._layers[i]->_active_values,_network._current_activation_function);
    }
}


void TrainerStrategy::train(Matrixd& input,Matrixd& answer,double learning_speed = 0.5,bool logging = false)
{
    _network.setInputLayer(input);
    _network.forwardPropogation();
    backPropogation(answer);
    _optimizer->updateWeights(learning_speed,_epoch);
    if(logging)std::cout << _network._current_loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,answer) << "\n";
    _epoch++;
}



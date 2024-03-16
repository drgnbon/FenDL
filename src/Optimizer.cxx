#include "FenDL/Optimizer.hxx"


void Optimizer::backPropogation( Matrixd right_answer ,std::shared_ptr<LossFunction> _loss_function){
    _network._layers[_network._layers.size()-1]->_derivation_neurons = _loss_function->getDerivationLoss(_network._layers[_network._layers.size()-1]->_active_values, right_answer);

    for(long long i = _network._layers.size()-2; i >= 0; --i)
    {
        _network._layers[i]->calculateDerivation(_network._layers[i]->_weights, _network._layers[i+1]->_derivation_neurons, _network._layers[i+1]->_values, _network._layers[i]->_active_values,_network._current_activation_function);
    }
}
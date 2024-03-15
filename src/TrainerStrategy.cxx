#include "FenDL/TrainerStrategy.hxx"


void TrainerStrategy::backPropogation( Matrixd right_answer){
    _network._layers[_network._layers.size()-1]->_derivation_neurons = _loss_function->getDerivationLoss(_network._layers[_network._layers.size()-1]->_active_values, right_answer);

    for(long long i = _network._layers.size()-2; i >= 0; --i)
    {
        _network._layers[i]->calculateDerivation(_network._layers[i]->_weights, _network._layers[i+1]->_derivation_neurons, _network._layers[i+1]->_values, _network._layers[i]->_active_values,_network._current_activation_function);
    }
}


void TrainerStrategy::fit(Matrixd& input,Matrixd& answer,double learning_speed = 0.5,bool logging = false)
{
    _network.setInputLayer(input);
    _network.forwardPropogation();
    backPropogation(answer);
    _optimizer->updateWeights(learning_speed,_epoch);
    if(logging)std::cout << _loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,answer) << "\n";
    _epoch++;
}

void TrainerStrategy::fit(Branch branch,int count_of_epochs, double learning_speed, bool logging)
{
    for(_epoch = 0;_epoch < count_of_epochs;++_epoch)
    {
        for(int test_count = 0;test_count < branch._count_of_tests;++test_count)
        {
            _network.setInputLayer(branch._inputs[test_count]);
            _network.forwardPropogation();
            backPropogation(branch._targets[test_count]);
            _optimizer->updateWeights(learning_speed,_epoch);
            if(logging)std::cout << _loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,branch._targets[test_count]) << "\n";
        }
    }
}






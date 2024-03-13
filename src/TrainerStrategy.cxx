#include "FenDL/TrainerStrategy.hxx"

TrainerStrategy::TrainerStrategy() {
    _optimizer = std::make_shared<GD>();
    _loss_function = std::make_shared<SquareError>();
}

TrainerStrategy::TrainerStrategy(std::shared_ptr<Optimizer> optimizer) {
    _optimizer = optimizer;
    _loss_function = std::make_shared<SquareError>();
}

TrainerStrategy::TrainerStrategy(std::shared_ptr<Optimizer> optimizer ,std::shared_ptr<LossFunction> lossFunction)
{
    _optimizer = optimizer;
    _loss_function = lossFunction;
}

void TrainerStrategy::backPropogation(NeuralNetwork& network , Matrixd right_answer){
    network._layers[network._layers.size()-1]->_derivation_neurons = _loss_function->getDerivationLoss(network._layers[network._layers.size()-1]->_active_values, right_answer);

    for(long long i = network._layers.size()-2; i >= 0; --i)
    {
        network._layers[i]->calculateDerivation(network._layers[i]->_weights, network._layers[i+1]->_derivation_neurons, network._layers[i+1]->_values, network._layers[i]->_active_values,network._current_activation_function);
    }
}

void TrainerStrategy::train(NeuralNetwork& network,Matrixd input,Matrixd answer,double learning_speed = 0.5,bool logging = false)
{
    network.setInputLayer(input);
    network.forwardPropogation();
    backPropogation(network,answer);
    for(int i = 0;i <  network._layers.size()-1;i++){
        _optimizer->updateWeights(network._layers[i]->_weights,network._layers[i]->_gradient,learning_speed);
    }
    if(logging)std::cout << network._current_loss_function->getMediumLoss(network._layers[network._layers.size()-1]->_active_values,answer) << "\n";
}



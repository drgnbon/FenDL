#include "FenDL/TrainerStrategy.hxx"





void TrainerStrategy::fit(Matrixd& input,Matrixd& answer,double learning_speed = 0.5,bool logging = false)
{
    _network.setInputLayer(input);
    _network.forwardPropogation();
    _optimizer->backPropogation(answer,_loss_function);
    _optimizer->updateWeights(answer,_loss_function,learning_speed,_epoch);
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
            _optimizer->backPropogation(branch._targets[test_count],_loss_function);
            _optimizer->updateWeights(branch._targets[test_count],_loss_function,learning_speed,_epoch);
            if(logging)std::cout << _loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,branch._targets[test_count]) << "\n";
        }
    }
}






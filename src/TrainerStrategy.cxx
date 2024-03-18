#include "FenDL/TrainerStrategy.hxx"





void TrainerStrategy::fit(Matrixd& input,Matrixd& answer,double learning_speed = 0.5,bool logging = false,double epsilon)
{
    _network.setInputLayer(input);
    _network.forwardPropogation();
    _optimizer->backPropogation(answer,_loss_function);
    _optimizer->updateWeights(answer,_loss_function,learning_speed,_epoch);
    if(logging)std::cout << _loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,answer) << "\n";
    _epoch++;
    //if(_epoch > 10.0)_epoch = 0.0;
}

void TrainerStrategy::fit(Branch branch,int count_of_epochs, double learning_speed, bool logging,double epsilon)
{
    _save_weights = false;
    _average_loss = 0;
    _average_percentage = 0;

    _learning_speed = learning_speed;
    for(_epoch = 0;_epoch < count_of_epochs;++_epoch)
    {
        auto time_for_branch = clock();

        _branch_size = branch._count_of_tests;
        double _old_error = 0,_new_error = 0,average_loss = 0,average_percentage = 0;

        for(_test_number = 0;_test_number < branch._count_of_tests;++_test_number)
        {

            auto time_for_test = clock();

            _network.setInputLayer(branch._inputs[_test_number]);
            _network.forwardPropogation();
            _optimizer->backPropogation(branch._targets[_test_number],_loss_function);
            _optimizer->updateWeights(branch._targets[_test_number],_loss_function,learning_speed,_epoch);
            _old_error = _new_error;
            _new_error = _loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,branch._targets[_test_number]);
            _error_decreeding_speed = _new_error - _old_error;
            average_loss += _new_error;
            average_percentage += getPercent(branch._targets[_test_number],epsilon);
            if(logging)std::cout << _loss_function->getMediumLoss(_network._layers[_network._layers.size()-1]->_active_values,branch._targets[_test_number]) << "\n";
            _loss_history.push_back(_new_error);
            _time_for_test = clock() - time_for_test;
        }
        _loss_history.clear();
        _average_loss = average_loss/double(branch._count_of_tests);
        _average_percentage = average_percentage / double(branch._count_of_tests);
        _time_for_branch = clock() - time_for_branch;
    }
}

void TrainerStrategy::setHyperparameters(double alfa, double gamma, double epsilon)
{
    _optimizer->_epsilon = epsilon;
    _optimizer->_gamma = gamma;
    _optimizer->_alfa = alfa;
}

double TrainerStrategy::getPercent(Matrixd answer,double epsilon){
    double percent = 0;
    for(int i = 0;i < answer.rows();i++){
        for(int j = 0;j < answer.cols();j++){
            if(abs(_network._layers[_network._layers.size()-1]->_active_values(i,j) - answer(i,j)) > epsilon)
                percent++;
        }
    }
    return  100.0*percent/double(answer.size());
}



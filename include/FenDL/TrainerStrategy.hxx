#ifndef FENDL_TRAINERSTRATEGY_HXX
#define FENDL_TRAINERSTRATEGY_HXX



//this class may be added in future:)



#include "Config.hxx"


typedef Eigen::MatrixXd Matrixd;


class TrainerStrategy {
public:
    TrainerStrategy() = default;


    void train(NeuralNetwork& network,Matrixd input,Matrixd answer,bool logging)
    {
        while(true)
        {
            network.setInputLayer(input);
            network.forwardPropogation();
            network.backPropogation(answer);
            for(int i = 0;i <  network._layers.size()-1;i++){
                //_current_optimizer->updateWeights(_layers[i]->_weights,_layers[i]->_gradient,learning_speed);
                network._layers[i]->_weights -= 0.5* network._layers[i]->_gradient;
            }
            std::cout << network._current_loss_function->getMediumLoss(network._layers[network._layers.size()-1]->_active_values,answer) << "\n";
        }
    }


private:
    double _speed_of_learning = 0.01;


};


#endif

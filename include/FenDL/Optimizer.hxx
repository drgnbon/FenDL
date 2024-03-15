#ifndef FENDL_OPTIMIZER_HXX
#define FENDL_OPTIMIZER_HXX

#include "Eigen/Core"
#include <map>
#include <FenDL/NeuralNetwork.hxx>


typedef Eigen::MatrixXd Matrixd;

class Optimizer
{
public:
    explicit Optimizer(NeuralNetwork& network):_network{network}{};

    virtual void updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,double learning_speed ,double epoch ) = 0;

    void backPropogation( Matrixd right_answer ,std::shared_ptr<LossFunction> _loss_function){
        _network._layers[_network._layers.size()-1]->_derivation_neurons = _loss_function->getDerivationLoss(_network._layers[_network._layers.size()-1]->_active_values, right_answer);

        for(long long i = _network._layers.size()-2; i >= 0; --i)
        {
            _network._layers[i]->calculateDerivation(_network._layers[i]->_weights, _network._layers[i+1]->_derivation_neurons, _network._layers[i+1]->_values, _network._layers[i]->_active_values,_network._current_activation_function);
        }
    }

protected:
    NeuralNetwork& _network;

};




#endif
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
    virtual void updateWeights(double ls,double epoch) = 0;


protected:
    NeuralNetwork& _network;

};




#endif
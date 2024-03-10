#ifndef FENDL_LOSSFUNCTION_HXX
#define FENDL_LOSSFUNCTION_HXX

#include "Eigen/Core"
#include "FenDL/ActivateFunction.hxx"

class LossFunction
{
public:
    virtual double getMediumLoss(Eigen::MatrixXd active_value,Eigen::MatrixXd right_answer) = 0;

    virtual Eigen::MatrixXd getDerivationLoss(Eigen::MatrixXd weights_this_layer,Eigen::MatrixXd derivation_next_layer,Eigen::MatrixXd values_next_layer,ActivationFunction* activation_function) = 0;
};

#endif

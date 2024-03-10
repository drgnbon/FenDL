#ifndef FENDL_SQUAREERROR_HXX
#define FENDL_SQUAREERROR_HXX

#include <FenDL/LossFunction.hxx>

class SquareError : public LossFunction
{
public:
  double getMediumLoss(Eigen::MatrixXd active_value,Eigen::MatrixXd right_answer) override;

  Eigen::MatrixXd getDerivationLoss(Eigen::MatrixXd weights_this_layer,Eigen::MatrixXd derivation_next_layer,Eigen::MatrixXd values_next_layer,ActivationFunction* activation_function) override;
};

#endif

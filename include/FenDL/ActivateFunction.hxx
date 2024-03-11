#ifndef FENDL_ACTIVATIONFUNCTION_HXX
#define FENDL_ACTIVATIONFUNCTION_HXX


#include "Eigen/Core"


class ActivationFunction
{

public:

  ActivationFunction(){}

  virtual double getActivateValue(double value) = 0;

  virtual Eigen::MatrixXd getDerivateMatrix(Eigen::MatrixXd matrix) = 0;
  virtual Eigen::MatrixXd getActivateMatrix(Eigen::MatrixXd matrix) = 0;
};

#endif

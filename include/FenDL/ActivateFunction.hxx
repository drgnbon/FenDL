#ifndef FENDL_ACTIVATIONFUNCTION_HXX
#define FENDL_ACTIVATIONFUNCTION_HXX


#include "Eigen/Core"


class ActivationFunction
{

public:

  ActivationFunction(){}

  virtual double getActivateValue(double value) = 0;
  virtual double getDerivateValue(double value) = 0;

  Eigen::MatrixXd getActivateMatrix(Eigen::MatrixXd matrix) {
	  for (int i = 0; i < matrix.rows(); ++i) {
		  for (int j = 0; j < matrix.cols(); ++j) {
			  matrix(i, j) = getActivateValue(matrix(i, j));
		  }
	  }
	  return matrix;
  }

  Eigen::MatrixXd getDerivateMatrix(Eigen::MatrixXd matrix) {
	  for (int i = 0; i < matrix.rows(); ++i) {
		  for (int j = 0; j < matrix.cols(); ++j) {
			  matrix(i, j) = getDerivateValue(matrix(i, j));
		  }
	  }
	  return matrix;
  }


};

#endif

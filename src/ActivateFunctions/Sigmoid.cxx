#include "FenDL/ActivateFunctions/Sigmoid.hxx"
#include <iostream>

double Sigmoid::getActivateValue(double value) {

    return 0;
}
Eigen::MatrixXd Sigmoid::getActivateMatrix(Eigen::MatrixXd matrix) {
  for (int i = 0; i < matrix.rows(); ++i) {
    for (int j = 0; j < matrix.cols(); ++j) {
      matrix(i, j) = 1.0 / (1.0 + std::exp(-matrix(i, j)));
    }
  }
  return matrix;
}
Sigmoid::Sigmoid(){};

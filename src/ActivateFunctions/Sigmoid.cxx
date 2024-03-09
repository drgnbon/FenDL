#include "FenDL/ActivateFunctions/Sigmoid.hxx"
#include <iostream>

double Sigmoid::getActivateValue(double value) {

    return 1.0 / (1.0 + exp(-value));
}

Eigen::MatrixXd Sigmoid::getActivateMatrix(Eigen::MatrixXd matrix) {
  for (int i = 0; i < matrix.rows(); ++i) {
    for (int j = 0; j < matrix.cols(); ++j) {
      matrix(i, j) = 1.0 / (1.0 + exp(-matrix(i, j)));
    }
  }
  return matrix;
}
Sigmoid::Sigmoid(){};


Eigen::MatrixXd Sigmoid::getDerivateMatrix(Eigen::MatrixXd matrix) {
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            double x = getActivateValue(matrix(i,j));
            matrix(i, j) = x / (1.0 - x);
        }
    }
    return matrix;
}
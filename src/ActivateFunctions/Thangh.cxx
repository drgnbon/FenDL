#include "FenDL/ActivateFunctions/Thangh.hxx"

double Thangh::getActivateValue(double value) {

	return  (exp(value) - exp(-value))/(exp(value) + exp(-value))  ;
}

Eigen::MatrixXd Thangh::getActivateMatrix(Eigen::MatrixXd matrix) {
	for (int i = 0; i < matrix.rows(); ++i) {
		for (int j = 0; j < matrix.cols(); ++j) {
			matrix(i, j) = (exp(matrix(i,j)) - exp(-matrix(i,j)))/(exp(matrix(i,j)) + exp(-matrix(i,j)));
		}
	}
	return matrix;
}
Thangh::Thangh(){};


Eigen::MatrixXd Thangh::getDerivateMatrix(Eigen::MatrixXd matrix) {
	for (int i = 0; i < matrix.rows(); ++i) {
		for (int j = 0; j < matrix.cols(); ++j) {
			matrix(i, j) = 1 - getActivateValue(matrix(i,j))*getActivateValue(matrix(i,j));
		}
	}
	return matrix;
}
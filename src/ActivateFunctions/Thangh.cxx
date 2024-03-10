#include "FenDL/ActivateFunctions/Thangh.hxx"

double Thangh::getActivateValue(double value) {

	return  (exp(value) - exp(-value))/(exp(value) + exp(-value))  ;
}

Eigen::MatrixXd Thangh::getActivateMatrix(Eigen::MatrixXd matrix) {
	for (int i = 0; i < matrix.rows(); ++i) {
		for (int j = 0; j < matrix.cols(); ++j) {
			double value = matrix(i,j);
			matrix(i, j) = (exp(value) - exp(-value))/(exp(value) + exp(-value));
		}
	}
	return matrix;
}
Thangh::Thangh(){};


Eigen::MatrixXd Thangh::getDerivateMatrix(Eigen::MatrixXd matrix) {
	for (int i = 0; i < matrix.rows(); ++i) {
		for (int j = 0; j < matrix.cols(); ++j) {
			double x = getActivateValue(matrix(i,j));
			matrix(i, j) = 1 - x*x;
		}
	}
	return matrix;
}
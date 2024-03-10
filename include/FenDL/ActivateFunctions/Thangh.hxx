#ifndef FENDL_THANGH_HXX
#define FENDL_THANGH_HXX

#include <FenDL/ActivateFunction.hxx>

class Thangh :public  ActivationFunction {
public:
	Thangh();

	double getActivateValue(double value) override;

	Eigen::MatrixXd getDerivateMatrix(Eigen::MatrixXd matrix) override;

	Eigen::MatrixXd getActivateMatrix(Eigen::MatrixXd matrix) override;
};


#endif

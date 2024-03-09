#ifndef FENDL_SIGMOID_HXX
#define FENDL_SIGMOID_HXX

#include <FenDL/ActivateFunction.hxx>


class Sigmoid :public ActivationFunction {
public:
    Sigmoid();

    double getActivateValue(double value) override;

    Eigen::MatrixXd getActivateMatrix(Eigen::MatrixXd matrix) override;

};


#endif

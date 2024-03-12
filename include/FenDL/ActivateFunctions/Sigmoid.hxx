#ifndef FENDL_SIGMOID_HXX
#define FENDL_SIGMOID_HXX

#include <FenDL/ActivateFunction.hxx>


class Sigmoid :public ActivationFunction {
public:
    Sigmoid();

    double getActivateValue(double value) override;
	double getDerivateValue(double value) override;


};


#endif

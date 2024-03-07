#ifndef FENDL_RELU_HXX
#define FENDL_RELU_HXX

#include <FenDL/ActivateFunctions/ActivateFunction.hxx>

class ReLU : ActivationFunction {
public:
    double getActivateValue() override;
};


#endif

#ifndef FENDL_LRELU_HXX
#define FENDL_LRELU_HXX

#include <FenDL/ActivateFunctions/ActivateFunction.hxx>

class LReLU : ActivationFunction {
public:
    double getActivateValue() override;
};


#endif

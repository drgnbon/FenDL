#ifndef FENDL_LRELU_HXX
#define FENDL_LRELU_HXX

#include "ActivationFunction.hxx"

class LReLU : ActivationFunction{
public:
    double getActivateValue() override;
};


#endif

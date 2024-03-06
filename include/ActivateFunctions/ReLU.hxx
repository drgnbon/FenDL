#ifndef FENDL_RELU_HXX
#define FENDL_RELU_HXX

#include "ActivationFunction.hxx"

class ReLU : ActivationFunction{
public:
    double getActivateValue() override;
};


#endif

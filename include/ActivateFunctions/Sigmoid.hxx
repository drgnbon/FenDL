#ifndef FENDL_SIGMOID_HXX
#define FENDL_SIGMOID_HXX

#include "ActivationFunction.hxx"

class Sigmoid : ActivationFunction{
public:
    double getActivateValue() override;
};


#endif

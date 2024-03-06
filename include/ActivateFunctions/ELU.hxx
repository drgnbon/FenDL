#ifndef FENDL_ELU_HXX
#define FENDL_ELU_HXX

#include "ActivationFunction.hxx"

class ELU : ActivationFunction {
public:
    double getActivateValue() override;
};


#endif//FENDL_ELU_HXX

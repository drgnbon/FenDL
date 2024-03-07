#ifndef FENDL_ELU_HXX
#define FENDL_ELU_HXX

#include <FenDL/ActivateFunctions/ActivateFunction.hxx>

class ELU : ActivationFunction {
public:
    double getActivateValue() override;
};

#endif//FENDL_ELU_HXX

#ifndef FENDL_SILU_HXX
#define FENDL_SILU_HXX

#include <FenDL/ActivateFunction.hxx>

class SiLU : public  ActivationFunction{
public:
    SiLU();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

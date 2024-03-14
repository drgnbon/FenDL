#ifndef FENDL_SOFTPLUS_HXX
#define FENDL_SOFTPLUS_HXX

#include <FenDL/ActivateFunction.hxx>

class SoftPlus : public  ActivationFunction{
public:
    SoftPlus();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

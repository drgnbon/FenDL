#ifndef FENDL_SELU_HXX
#define FENDL_SELU_HXX

#include <FenDL/ActivateFunction.hxx>

class SELU : public  ActivationFunction{
public:
    SELU();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

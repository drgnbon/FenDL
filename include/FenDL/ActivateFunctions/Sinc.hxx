#ifndef FENDL_SINC_HXX
#define FENDL_SINC_HXX

#include <FenDL/ActivateFunction.hxx>

class Sinc : public  ActivationFunction{
public:
    Sinc();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif
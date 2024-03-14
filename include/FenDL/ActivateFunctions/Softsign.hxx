#ifndef FENDL_SOFTSIGN_HXX
#define FENDL_SOFTSIGN_HXX

#include <FenDL/ActivateFunction.hxx>

class Softsign : public  ActivationFunction{
public:
    Softsign();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

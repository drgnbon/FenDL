#ifndef FENDL_BENTI_HXX
#define FENDL_BENTI_HXX

#include <FenDL/ActivateFunction.hxx>

class Benti : public  ActivationFunction {
public:
    Benti();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

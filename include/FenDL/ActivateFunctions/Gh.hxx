#ifndef FENDL_GH_HXX
#define FENDL_GH_HXX

#include <FenDL/ActivateFunction.hxx>

class Gh : public  ActivationFunction{
public:
    Gh();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

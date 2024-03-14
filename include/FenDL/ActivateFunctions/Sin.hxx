#ifndef FENDL_SIN_HXX
#define FENDL_SIN_HXX

#include <FenDL/ActivateFunction.hxx>

class Sin : public  ActivationFunction{
public:
    Sin();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

#ifndef FENDL_LINEAR_HXX
#define FENDL_LINEAR_HXX

#include <FenDL/ActivateFunction.hxx>

class Linear : public  ActivationFunction{
public:
    Linear();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

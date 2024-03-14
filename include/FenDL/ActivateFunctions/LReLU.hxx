#ifndef FENDL_LRELU_HXX
#define FENDL_LRELU_HXX

#include <FenDL/ActivateFunction.hxx>

class LReLU : public  ActivationFunction{
public:
    LReLU();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

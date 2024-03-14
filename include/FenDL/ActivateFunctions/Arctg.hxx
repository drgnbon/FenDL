#ifndef FENDL_ARCTG_HXX
#define FENDL_ARCTG_HXX


#include <FenDL/ActivateFunction.hxx>

class Arctg : public  ActivationFunction{
public:
    Arctg();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;

};
#endif

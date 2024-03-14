#ifndef FENDL_ELU_HXX
#define FENDL_ELU_HXX

#include <FenDL/ActivateFunction.hxx>

class ELU : public  ActivationFunction{
public:
    ELU();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

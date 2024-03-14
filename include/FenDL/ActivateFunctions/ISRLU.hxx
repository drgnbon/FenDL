#ifndef FENDL_ISRLU_HXX
#define FENDL_ISRLU_HXX

#include <FenDL/ActivateFunction.hxx>

class ISRLU : public  ActivationFunction{
public:
    ISRLU();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

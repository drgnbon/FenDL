#ifndef FENDL_ISRU_HXX
#define FENDL_ISRU_HXX

#include <FenDL/ActivateFunction.hxx>

class ISRU : public  ActivationFunction{
public:
    ISRU();

    double getActivateValue(double value) override;
    double getDerivateValue(double value) override;
};


#endif

#ifndef FENDL_THANGH_HXX
#define FENDL_THANGH_HXX

#include <FenDL/ActivateFunction.hxx>

class Thangh :public  ActivationFunction {
public:
	Thangh();

	double getActivateValue(double value) override;
	double getDerivateValue(double value) override;

};


#endif

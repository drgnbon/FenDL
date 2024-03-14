#ifndef FENDL_TH_HXX
#define FENDL_TH_HXX

#include <FenDL/ActivateFunction.hxx>

class Th : public  ActivationFunction {
public:
	Th();

	double getActivateValue(double value) override;
	double getDerivateValue(double value) override;

};


#endif

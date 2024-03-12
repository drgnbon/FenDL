//
// Created by Andrey on 12.03.2024.
//

#ifndef FENDL_RELU_HXX
#define FENDL_RELU_HXX
#include <FenDL/ActivateFunction.hxx>

class RELU : public ActivationFunction {
public:
	RELU();

	double getActivateValue(double value) override;
	double getDerivateValue(double value) override;


};



#endif //FENDL_RELU_HXX

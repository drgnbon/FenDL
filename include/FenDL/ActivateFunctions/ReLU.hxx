//
// Created by Andrey on 12.03.2024.
//

#ifndef FENDL_RELU_HXX
#define FENDL_RELU_HXX
#include <FenDL/ActivateFunction.hxx>

class ReLU : public ActivationFunction {
public:
	ReLU();

	double getActivateValue(double value) override;
	double getDerivateValue(double value) override;


};



#endif //FENDL_RELU_HXX

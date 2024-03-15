#ifndef FENDL_GD_HXX
#define FENDL_GD_HXX

#include <FenDL/Optimizer.hxx>

class GD : public Optimizer {
public:
	void updateWeights(Matrixd& weights,Matrixd& gradient,int number_of_layer,double ls ,double epoch) override;


};

#endif
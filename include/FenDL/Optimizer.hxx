#ifndef FENDL_OPTIMIZER_HXX
#define FENDL_OPTIMIZER_HXX

#include "Eigen/Core"

typedef Eigen::MatrixXd Matrixd;

class Optimizer
{
public:
	virtual void updateWeights(Matrixd& weights,Matrixd& gradient,double ls) = 0;
};

#endif

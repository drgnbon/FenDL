#ifndef FENDL_OPTIMIZER_HXX
#define FENDL_OPTIMIZER_HXX

#include <Eigen/Dense>

class Optimizer{
public:

	virtual void updateWeights(Eigen::MatrixXd& weights,Eigen::MatrixXd& gradient,double ls) = 0;




};




#endif //FENDL_OPTIMIZER_HXX

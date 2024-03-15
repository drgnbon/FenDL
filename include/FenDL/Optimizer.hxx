#ifndef FENDL_OPTIMIZER_HXX
#define FENDL_OPTIMIZER_HXX

#include "Eigen/Core"
#include <map>

typedef Eigen::MatrixXd Matrixd;

class Optimizer
{
public:
    //virtual ~Optimizer();


    virtual void updateWeights(Matrixd& weights,Matrixd& gradient,int number_of_layer,double ls = 0.5,double epoch = 1.0) = 0;

protected:



private:

};



#endif
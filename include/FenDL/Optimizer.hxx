#ifndef FENDL_OPTIMIZER_HXX
#define FENDL_OPTIMIZER_HXX

#include "Eigen/Core"

typedef Eigen::MatrixXd Matrixd;

class Optimizer
{
public:
    virtual void updateWeights(Matrixd& weights,Matrixd& gradient,double ls) = 0;

    virtual void updateWeights(Matrixd& weights,Matrixd& gradient,double ls,int epoch) = 0;

protected:
    double _gamma = 0.9;
    double _alfa =  0.999;
    double _epsilon = 1e-8;


private:

};

#endif
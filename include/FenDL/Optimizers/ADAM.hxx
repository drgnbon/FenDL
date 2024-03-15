#ifndef FENDL_ADAM_HXX
#define FENDL_ADAM_HXX

#include <FenDL/Optimizer.hxx>

class ADAM : public Optimizer{

private:
    double _gamma = 0.9;
    double _alfa =  0.999;
    double _epsilon = 1e-8;

    std::map<const Matrixd* , Matrixd> _history_speed;
    std::map<int, Matrixd> _history_moment;

    void updateWeights(Matrixd& weights,Matrixd& gradient,int number_of_layer,double ls,double epoch) override;
};


#endif



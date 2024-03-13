#ifndef FENDL_ADAM_HXX
#define FENDL_ADAM_HXX

#include <FenDL/Optimizer.hxx>

class ADAM : public Optimizer{
    void updateWeights(Matrixd& weights,Matrixd& gradient,double ls,double epoch) override;
};


#endif //FENDL_ADAM_HXX
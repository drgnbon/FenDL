#ifndef FENDL_ADAM_HXX
#define FENDL_ADAM_HXX

#include <FenDL/Optimizer.hxx>

class ADAM : public Optimizer{
public:
    explicit ADAM(NeuralNetwork& network);
    ~ADAM();

private:
    double _gamma = 0.9;
    double _alfa =  0.999;
    double _epsilon = 1e-8;
    Matrixd*  _history_speed;
    Matrixd* _history_moment;

    void updateWeights(double ls,double epoch) override;
};


#endif



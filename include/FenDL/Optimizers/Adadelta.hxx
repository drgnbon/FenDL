#ifndef FENDL_ADADELTA_HXX
#define FENDL_ADADELTA_HXX

#include <FenDL/Optimizer.hxx>

class Adadelta : public Optimizer
{
public:
    explicit Adadelta(NeuralNetwork& network);
    ~Adadelta();
    void updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,
                       double learning_speed,double epoch) override;

private:
    double _beta = 0.9;
    double _epsilon = 1e-8;
    Matrixd* _squared_gradient;
    Matrixd* _squared_updates;
};


#endif

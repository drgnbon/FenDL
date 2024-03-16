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
    Matrixd* _squared_gradient;
    Matrixd* _squared_updates;
};


#endif

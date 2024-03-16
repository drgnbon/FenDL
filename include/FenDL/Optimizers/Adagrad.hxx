#ifndef FENDL_ADAGRAD_HXX
#define FENDL_ADAGRAD_HXX

#include <FenDL/Optimizer.hxx>


class Adagrad : public Optimizer{
public:
    explicit Adagrad(NeuralNetwork& network);
    void updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,
                       double learning_speed,double epoch) override;
private:
    double _epsilon = 1e-8;
    Matrixd* _squared_gradient;
};


#endif

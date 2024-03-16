#ifndef FENDL_GD_HXX
#define FENDL_GD_HXX

#include <FenDL/Optimizer.hxx>

class GD : public Optimizer {
public:

    explicit GD(NeuralNetwork& network);
    void updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,
                       double learning_speed,double epoch) override;
};


#endif
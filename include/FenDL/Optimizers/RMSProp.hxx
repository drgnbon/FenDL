#ifndef FENDL_RMSPROP_HXX
#define FENDL_RMSPROP_HXX

#include <FenDL/Optimizer.hxx>

class RMSProp : public Optimizer{
public:
    explicit RMSProp(NeuralNetwork& network);
    ~RMSProp();
    void updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,
                       double learning_speed,double epoch) override;
private:
    Matrixd* _squared_gradient;
};


#endif
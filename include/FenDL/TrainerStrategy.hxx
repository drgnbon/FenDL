#ifndef FENDL_TRAINERSTRATEGY_HXX
#define FENDL_TRAINERSTRATEGY_HXX


#include "Config.hxx"


typedef Eigen::MatrixXd Matrixd;


class TrainerStrategy {
public:

    std::shared_ptr<Optimizer> _optimizer;
    std::shared_ptr<LossFunction> _loss_function;

    TrainerStrategy();
    TrainerStrategy(std::shared_ptr<Optimizer> optimizer,std::shared_ptr<LossFunction> lossFunction);

    void backPropogation(NeuralNetwork& network , Matrixd right_answer);

    void train(NeuralNetwork& network,Matrixd input,Matrixd answer,double learning_speed,bool logging);


};


#endif

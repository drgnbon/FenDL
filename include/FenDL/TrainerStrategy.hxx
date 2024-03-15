#ifndef FENDL_TRAINERSTRATEGY_HXX
#define FENDL_TRAINERSTRATEGY_HXX


#include <FenDL/Optimizer.hxx>
#include <FenDL/NeuralNetwork.hxx>
#include <FenDL/Optimizers/GD.hxx>
#include <FenDL/Optimizers/ADAM.hxx>

typedef Eigen::MatrixXd Matrixd;


class TrainerStrategy {
public:

    TrainerStrategy(NeuralNetwork& network,std::shared_ptr<Optimizer> optimizer,std::shared_ptr<LossFunction> loss_function):
        _network{network},
        _optimizer{optimizer},
        _loss_function{loss_function},
        _epoch{0}{};

    TrainerStrategy(NeuralNetwork& network):
        _network{network},
        _optimizer{std::make_shared<GD>(network)},
        _loss_function{std::make_shared<SquareError>()},
        _epoch{0}{};



    void backPropogation( Matrixd right_answer);
    void train(Matrixd& input,Matrixd& answer,double learning_speed,bool logging);

private:
    double _epoch;
    std::shared_ptr<Optimizer> _optimizer;
    std::shared_ptr<LossFunction> _loss_function;
    NeuralNetwork& _network;
};


#endif

#ifndef FENDL_TRAINERSTRATEGY_HXX
#define FENDL_TRAINERSTRATEGY_HXX


#include <FenDL/Optimizer.hxx>
#include <FenDL/Branch.hxx>
#include <FenDL/NeuralNetwork.hxx>
#include <FenDL/Optimizers/GD.hxx>
#include <FenDL/Optimizers/ADAM.hxx>

typedef Eigen::MatrixXd Matrixd;


class TrainerStrategy {
public:

    explicit TrainerStrategy(NeuralNetwork& network):
            _network{network},
            _optimizer{std::make_shared<GD>(network)},
            _loss_function{std::make_shared<SquareError>()},
            _epoch{0}{};


    template<typename Optimizator>
    typename std::enable_if<std::is_base_of<Optimizer, Optimizator>::value>::type
    setOptimizer(NeuralNetwork& network)
    {
        _optimizer = std::make_shared<Optimizator>(network);
    }


    template<typename Function>
    typename std::enable_if<std::is_base_of<LossFunction, Function>::value>::type
    setLossFunction()
    {
        _loss_function = std::make_shared<Function>();
    }

    void backPropogation( Matrixd right_answer);



    void fit(Matrixd& input,Matrixd& answer,double learning_speed,bool logging);

    void fit(Branch branch,int epochs,double learning_speed,bool logging);





public:
    std::shared_ptr<LossFunction> _loss_function;
private:
    double _epoch;
    std::shared_ptr<Optimizer> _optimizer;

    NeuralNetwork& _network;
};


#endif

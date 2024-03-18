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



    void setHyperparameters(double alfa,double gamma,double epsilon);

    void fit(Matrixd& input,Matrixd& answer,double learning_speed,bool logging,double epsilon = 1e-8);

    void fit(Branch branch,int epochs,double learning_speed,bool logging,double epsilon = 1e-8);

    double getPercent(Matrixd answer,double epsilon);

    double _average_loss,
            _average_percentage,_time_for_branch,
            _time_for_test,_error_decreeding_speed,_learning_speed;
    int _test_number,_epoch,_branch_size;
    bool _save_weights;
    std::vector<double> _loss_history;
    std::shared_ptr<LossFunction> _loss_function;
    NeuralNetwork& _network;
private:

    std::shared_ptr<Optimizer> _optimizer;


};


#endif

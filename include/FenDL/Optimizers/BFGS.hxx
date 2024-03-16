#ifndef FENDL_BFGS_HXX
#define FENDL_BFGS_HXX

#include <FenDL/Optimizer.hxx>

typedef Eigen::VectorXd Vector;

class BFGS : public Optimizer {
public:
    explicit BFGS(NeuralNetwork& network);
    ~BFGS();

    void updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,
                       double learning_speed,double epoch) override;

private:

    Matrixd *_inversed_hessian,*I;
    Vector *y,*s,*_old_gradient,*_old_weights,*_new_weights,*_new_gradient;
    double ro;
};

#endif

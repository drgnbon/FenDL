#ifndef FENDL_OPTIMIZER_HXX
#define FENDL_OPTIMIZER_HXX


#include <Eigen/Dense>

namespace FenDL{


class Optimizer{
protected:
    typedef Eigen::MatrixXd Matrix;
    typedef Eigen::VectorXd Vector;
public:
    virtual ~Optimizer(){};
    virtual void Reset(){};
    virtual void UpdateWeights() = 0;

};

}




#endif //FENDL_OPTIMIZER_HXX

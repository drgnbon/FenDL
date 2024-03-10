#include "FenDL/LossFunctions/SquareError.hxx"


double SquareError::getMediumLoss(Eigen::MatrixXd active_value,Eigen::MatrixXd right_answer)
{
    return Eigen::VectorXd(active_value - right_answer).squaredNorm();
}

Eigen::MatrixXd SquareError::getDerivationLoss(Eigen::MatrixXd active_value,Eigen::MatrixXd right_answer)
{
  return  2*(active_value-right_answer);
}

#include "FenDL/LossFunctions/SquareError.hxx"


double SquareError::getMediumLoss(Eigen::MatrixXd active_value,Eigen::MatrixXd right_answer)
{
  double square_error = 0;
  for (int i = 0; i < active_value.rows(); ++i)
    for (int j = 0; j < active_value.cols(); ++j)
      square_error += (active_value(i, j) - right_answer(i, j))*(active_value(i, j) - right_answer(i, j));
  return square_error;
}







Eigen::MatrixXd SquareError::getDerivationLoss(Eigen::MatrixXd weights_this_layer,Eigen::MatrixXd derivation_next_layer,Eigen::MatrixXd values_next_layer,ActivationFunction *activation_function)
{
  return  Eigen::MatrixXd(derivation_next_layer.array() * activation_function->getDerivateMatrix(values_next_layer).array()) * weights_this_layer.transpose();
}

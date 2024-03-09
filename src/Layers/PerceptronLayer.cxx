#include "FenDL/Layers/PerceptronLayer.hxx"


PerceptronLayer::PerceptronLayer(size_t size_of_input, size_t size_of_output,bool is_last_layer) : Layer(size_of_input , size_of_output,is_last_layer)
{
  if(!is_last_layer)
    _weights = Eigen::MatrixXd::Random(size_of_input,size_of_output);

  _active_values = Eigen::MatrixXd::Zero(1,size_of_input);
  _values = Eigen::MatrixXd::Zero(1,size_of_input);
  _gradient = Eigen::MatrixXd::Zero(1,size_of_input);
}




PerceptronLayer::PerceptronLayer(size_t size_of_input) : Layer(size_of_input)
{
  _active_values = Eigen::MatrixXd::Zero(1,size_of_input);
  _values = Eigen::MatrixXd::Zero(1,size_of_input);
  _gradient = Eigen::MatrixXd::Zero(1,size_of_input);
}

void PerceptronLayer::buildWeightsForLayer(size_t size_of_output)
{
    _weights = Eigen::MatrixXd::Random(_size_of_input,size_of_output);
}


void PerceptronLayer::activateLayer(ActivationFunction* activation_function,Eigen::MatrixXd active_values_previous_layer,Eigen::MatrixXd weights_previous_layer)
{
  _values = active_values_previous_layer * weights_previous_layer;
  _active_values = activation_function->getActivateMatrix(_values);
}

#include "FenDL/Layers/PerceptronLayer.hxx"


PerceptronLayer::PerceptronLayer(size_t size_of_input, size_t size_of_output,bool is_last_layer) : Layer(size_of_input , size_of_output,is_last_layer)
{
  if(!is_last_layer){
	  _weights = Matrixd::Random(size_of_input,size_of_output);
	  _gradient = Matrixd::Zero(size_of_input,size_of_output);
  }
  _active_values = Matrixd::Zero(1,size_of_input);
  _values = Matrixd::Zero(1,size_of_input);
  _derivation_neurons = Matrixd::Zero(1,size_of_input);
}




PerceptronLayer::PerceptronLayer(size_t size_of_input) : Layer(size_of_input)
{
  _active_values = Matrixd::Zero(1,size_of_input);
  _values = Matrixd::Zero(1,size_of_input);
  _derivation_neurons = Matrixd::Zero(1,size_of_input);
}

void PerceptronLayer::buildWeightsForLayer(size_t size_of_output)
{
    _weights = Matrixd::Random(_size_of_input,size_of_output);
	_gradient = Matrixd::Zero(_size_of_input,size_of_output);
}


void PerceptronLayer::activateLayer(std::shared_ptr<ActivationFunction> activation_function,Matrixd active_values_previous_layer,Matrixd weights_previous_layer)
{
  _values = active_values_previous_layer * weights_previous_layer;
  _active_values = activation_function->getActivateMatrix(_values);
}

void PerceptronLayer::calculateDerivation(Matrixd weights_this_layer,Matrixd derivation_next_layer,Matrixd values_next_layer,Matrixd _active_values_this_layer,std::shared_ptr<ActivationFunction> activation_function)
{
    _derivation_neurons = Matrixd( derivation_next_layer.array() * activation_function->getDerivateMatrix(values_next_layer).array()    ) * weights_this_layer.transpose();
	_gradient = (_active_values_this_layer.transpose() * Matrixd(derivation_next_layer.array() * activation_function->getDerivateMatrix(values_next_layer).array()));
}

#ifndef FENDL_LAYER_HXX
#define FENDL_LAYER_HXX

#include <Eigen/Eigen>
#include <iostream>
#include <memory>
#include "FenDL/ActivateFunction.hxx"

typedef Eigen::MatrixXd Matrixd;


class Layer{
public:
	Matrixd _weights,_gradient;
	size_t _size_of_output;
	size_t _size_of_input;
	bool _is_last_layer;
	Matrixd _active_values,_values,_derivation_neurons;

  explicit Layer(size_t size_of_input, size_t size_of_output,bool is_last_layer) : _size_of_input{size_of_input}, _size_of_output{size_of_output},_is_last_layer{is_last_layer} {}

  explicit Layer(size_t size_of_input) : _size_of_input{size_of_input}{}

  virtual void buildWeightsForLayer(size_t size_of_output) = 0;

  virtual void activateLayer(std::shared_ptr<ActivationFunction> activation_function,Matrixd active_values_previous_layer,Matrixd weights_previous_layer) = 0;

  virtual void calculateDerivation(Matrixd weights_this_layer,Matrixd derivation_next_layer,Matrixd values_next_layer,Matrixd _active_values_this_layer,std::shared_ptr<ActivationFunction> activation_function) = 0;



};

#endif
#ifndef FENDL_LAYER_HXX
#define FENDL_LAYER_HXX

#include <Eigen/Eigen>
#include <iostream>

#include "FenDL/ActivateFunction.hxx"


class Layer{
public:
  explicit Layer(size_t size_of_input, size_t size_of_output,bool is_last_layer) : _size_of_input(size_of_input), _size_of_output(size_of_output),_is_last_layer(is_last_layer) {}

  explicit Layer(size_t size_of_input) : _size_of_input(size_of_input){}

  virtual void buildWeightsForLayer(size_t size_of_output) = 0;

  virtual void activateLayer(ActivationFunction* activation_function,Eigen::MatrixXd active_values_previous_layer,Eigen::MatrixXd weights_previous_layer) = 0;


  Eigen::MatrixXd _weights;
  size_t _size_of_output;
  size_t _size_of_input;
  bool _is_last_layer;
  Eigen::MatrixXd _active_values,_values,_gradient;
};

#endif
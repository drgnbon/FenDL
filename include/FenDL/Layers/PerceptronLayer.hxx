#ifndef FENDL_PERCEPTRONLAYER_HXX
#define FENDL_PERCEPTRONLAYER_HXX

#include <FenDL/Layer.hxx>
#include "FenDL/ActivateFunction.hxx"

class PerceptronLayer : public Layer {
public:
  // PerceptronLayer(int _size);

  PerceptronLayer(size_t size_of_input, size_t size_of_output,
                  bool is_last_layer); // this for full build

  explicit PerceptronLayer(size_t size_of_input);


  void buildWeightsForLayer(size_t size_of_output) override;

  void activateLayer(ActivationFunction* activation_function, Eigen::MatrixXd active_values_previous_layer, Eigen::MatrixXd weights_previous_layer) override;

  void calculateDerivation(Eigen::MatrixXd weights_this_layer,Eigen::MatrixXd derivation_next_layer,Eigen::MatrixXd values_next_layer,ActivationFunction* activation_function) override;

};
#endif

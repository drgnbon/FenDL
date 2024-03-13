#ifndef FENDL_PERCEPTRONLAYER_HXX
#define FENDL_PERCEPTRONLAYER_HXX

#include <FenDL/Layer.hxx>


class PerceptronLayer : public Layer {
public:
  // PerceptronLayer(int _size);

  PerceptronLayer(size_t size_of_input, size_t size_of_output,
                  bool is_last_layer); // this for full build

  explicit PerceptronLayer(size_t size_of_input);


  void buildWeightsForLayer(size_t size_of_output) override;

  void activateLayer(std::shared_ptr<ActivationFunction> activation_function, Matrixd active_values_previous_layer, Matrixd weights_previous_layer) override;

  void calculateDerivation(Matrixd weights_this_layer,Matrixd derivation_next_layer,Matrixd values_next_layer,Matrixd _active_values_this_layer,std::shared_ptr<ActivationFunction> activation_function) override;

};
#endif

#ifndef FENDL_NEURALNETWORK_HXX
#define FENDL_NEURALNETWORK_HXX


#include <initializer_list>
#include "Layer.hxx"
#include "Optimizer.hxx"
#include <memory>
#include <vector>
#include <FenDL/FenDL.hxx>



class NeuralNetwork
{
public:
  std::vector< std::shared_ptr<Layer> > layers;
  size_t _size_of_input = 0;

  ActivationFunction* _current_activation_function;
  LossFunction* _current_loss_function;
  Optimizer* _current_optimizer;

  NeuralNetwork();


  ~NeuralNetwork();//Deconstructor


  //WIP-----------------------------------------------------------------------------------------------

  void setActivationFunction(ActivationFunction& selected_activation_function)
  {
    _current_activation_function = &selected_activation_function;
  }
  void setLossFunction(LossFunction& selected_loss_function)
  {
      _current_loss_function = &selected_loss_function;
  }
  void setOptimizer(Optimizer& selected_optimizer)
  {
	_current_optimizer = &selected_optimizer;
  }

  void forwardFeed()
  {
    for(int i = 1;i < layers.size();++i)
      layers[i]->activateLayer(_current_activation_function,layers[i-1]->_active_values,layers[i-1]->_weights);
  }

  void backPropogation(Eigen::MatrixXd right_answer)
  {
    layers[layers.size()-1]->_derivation_neurons = _current_loss_function->getDerivationLoss(layers[layers.size()-1]->_active_values,right_answer);
    for(int i = layers.size()-2;i >= 0;--i)
    {
	    layers[i]->calculateDerivation(layers[i]->_weights,layers[i+1]->_derivation_neurons,layers[i+1]->_values,_current_activation_function);
	}
  }

  void learn(Eigen::MatrixXd input,Eigen::MatrixXd right_answer,double learning_speed){
	  layers[0]->_active_values = input;
	  forwardFeed();
	  backPropogation(right_answer);
	  for(int i = 0;i < layers.size();i++){
		_current_optimizer->updateWeights(layers[i]->_weights,layers[i]->_gradient,learning_speed);
	  }

  }

  Eigen::MatrixXd predict(Eigen::MatrixXd input){
	  layers[0]->_active_values = input;
	  forwardFeed();
	  return layers[layers.size()-1]->_active_values;
  }


  //creating network with add function
  template<typename LayerType>
  void addLayer(int size_of_layer) {
      layers.push_back(std::make_shared<LayerType>(size_of_layer));
  }
  void addComplete()
  {
    for(int i = 0;i < layers.size()-1;++i)
      layers[i]->buildWeightsForLayer(layers[i+1]->_size_of_input);
  }
  //creating network with add function


  //delete all layers
  void deleteAllLayers()
  {
    layers.clear();
  }
  //delete all layers


  //get info about network
  std::string getNetworkInfo()
  {
    std::string out_str;
    for(int i = 0;i < layers.size();++i)
    {
      out_str += "Layer " + std::to_string(i+1) + '\n';
      out_str += "Size of layer: " + std::to_string(layers[i]->_size_of_input) + '\n';
      out_str += "Weights: " + std::to_string(layers[i]->_weights.cols()) + ' ' + std::to_string(layers[i]->_weights.rows()) + "\n\n";
    }
    return out_str;
  }
  //get info about network

  //create network with initializer_list
  template<typename LayerType>
  void setLayers(std::initializer_list<int> structure) {
    layers.clear();
    auto it = structure.begin();
    auto end = structure.end();
    while (std::next(it) != end) {
      int current = *it;
      int next = *(std::next(it));
      layers.push_back(std::make_shared<LayerType>(current, next, false));
      ++it;
    }
    int last = *it;
    layers.push_back(std::make_shared<LayerType>(last, 0, false));

  }
  //create network with initializer_list
  //WIP-----------------------------------------------------------------------------------------------

};

#endif

#ifndef FENDL_NEURALNETWORK_HXX
#define FENDL_NEURALNETWORK_HXX


#include <initializer_list>
#include "Layer.hxx"
#include <memory>
#include <vector>
#include <FenDL/FenDL.hxx>



class NeuralNetwork
{
public:
  std::vector<std::shared_ptr<Layer>> layers;
  size_t _size_of_input = 0;

  ActivationFunction* _current_activation_function;



  NeuralNetwork();


  ~NeuralNetwork();//Deconstructor


  //WIP-----------------------------------------------------------------------------------------------

  void setActivationFunction(ActivationFunction& selected_activation_function)
  {
    _current_activation_function = &selected_activation_function;
  }
  void forwardFeed()
  {
    for(int i = 1;i < layers.size();++i)
      layers[i]->activateLayer(_current_activation_function,layers[i-1]->_active_values,layers[i-1]->_weights);
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

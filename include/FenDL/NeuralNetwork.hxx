#ifndef FENDL_NEURALNETWORK_HXX
#define FENDL_NEURALNETWORK_HXX

#include <initializer_list>
#include <memory>
#include <vector>

#include "Config.hxx"

typedef Eigen::MatrixXd Matrixd;

class NeuralNetwork
{
public:
    std::vector<std::shared_ptr<Layer> > _layers;
    std::shared_ptr<ActivationFunction> _current_activation_function;

    NeuralNetwork();
    ~NeuralNetwork();

    //set options
    template<typename Function>
    typename std::enable_if<std::is_base_of<ActivationFunction, Function>::value>::type
    setActivationFunction()
    {
        _current_activation_function = std::make_shared<Function>();
    }

    //creating network with add function
    template<typename LayerType>
    typename std::enable_if<std::is_base_of<Layer, LayerType>::value>::type
    addLayer(int size_of_layer) {
        _layers.push_back(std::make_shared<LayerType>(size_of_layer));
    }
    void addComplete() const;


    //creating network initializer_list
    template<typename LayerType>
    typename std::enable_if<std::is_base_of<Layer, LayerType>::value>::type
    setLayers(std::initializer_list<int> structure) {
        _layers.clear();
        auto it = structure.begin();
        auto end = structure.end();
        while (std::next(it) != end) {
            int current = *it;
            int next = *(std::next(it));
            _layers.push_back(std::make_shared<LayerType>(current, next, false));
            ++it;
        }
        int last = *it;
        _layers.push_back(std::make_shared<LayerType>(last, 0, true));
    }

    //delete all layers
    void deleteAllLayers();

    void setInputLayer(Matrixd input);

    //basic forward feed
    void forwardPropogation();

    //predict
    Matrixd predict(Matrixd& input);

    void SaveNeuralNetworkData(std::string path);
    void LoadNeuralNetworkData(std::string path);

};

#endif

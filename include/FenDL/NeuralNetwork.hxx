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
    std::shared_ptr<LossFunction> _current_loss_function;
    std::shared_ptr<Optimizer> _current_optimizer;

    NeuralNetwork();
    ~NeuralNetwork();

    //set options
    void setActivationFunction(std::shared_ptr<ActivationFunction> selected_activation_function);
    void setLossFunction(std::shared_ptr<LossFunction> selected_loss_function);
    void setOptimizer(std::shared_ptr<Optimizer> selected_optimizer);

    //creating network with add function
    template<typename LayerType>
    void addLayer(int size_of_layer,std::shared_ptr<Layer>) {
        _layers.push_back(std::make_shared<LayerType>(size_of_layer));
    }
    void addComplete() const
    {
        if (_layers.size() < 2) return;
        for(int i = 0;i < _layers.size()-1;++i)
            _layers[i]->buildWeightsForLayer(_layers[i+1]->_size_of_input);
    }

    //creating network initializer_list
    template<typename LayerType>
    void setLayers(std::initializer_list<int> structure) {
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

	//basic back propogation
	void backPropogation(Matrixd& right_answer);

    //predict
    Matrixd predict(Matrixd input);

    //learning
    void learn(Matrixd input,Matrixd right_answer,double learning_speed);


};

#endif

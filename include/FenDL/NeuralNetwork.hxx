#ifndef FENDL_NEURALNETWORK_HXX
#define FENDL_NEURALNETWORK_HXX

#include <initializer_list>
#include <memory>
#include <vector>

#include "Config.hxx"


class NeuralNetwork
{
public:
    std::vector<std::shared_ptr<Layer> > _layers;
    std::shared_ptr<ActivationFunction> _current_activation_function;
    std::shared_ptr<LossFunction> _current_loss_function;
    std::shared_ptr<Optimizer> _current_optimizer;


    NeuralNetwork()
    {
        _current_activation_function = std::make_shared<Sigmoid>();
        _current_loss_function = std::make_shared<SquareError>();
        _current_optimizer = std::make_shared<GD>();
    }
    ~NeuralNetwork() = default;



    //WIP-----------------------------------------------------------------------------------------------

    //set options_____________________________________________________________________________________
    void setActivationFunction(std::shared_ptr<ActivationFunction> selected_activation_function)
    {
        _current_activation_function = std::move(selected_activation_function);
    }
    void setLossFunction(std::shared_ptr<LossFunction> selected_loss_function)
    {
        _current_loss_function = std::move(selected_loss_function);
    }
    void setOptimizer(std::shared_ptr<Optimizer> selected_optimizer)
    {
        _current_optimizer = std::move(selected_optimizer);
    }


    //creating network with add function_______________________________________________________________
    template<typename LayerType>
    void addLayer(int size_of_layer) {
        _layers.push_back(std::make_shared<LayerType>(size_of_layer));
    }
    void addComplete() const
    {
        if (_layers.size() < 2) return;
        for(int i = 0;i < _layers.size()-1;++i)
            _layers[i]->buildWeightsForLayer(_layers[i+1]->_size_of_input);
    }

    //creating network initializer_list_______________________________________________________________
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

    //delete all layers_______________________________________________________________
    void deleteAllLayers()
    {
        _layers.clear();
    }

    //basic forward feed___________________________________________________________________________
    void forwardFeed()
    {
        for(long long i = 1;i < _layers.size();++i)
        {
            _layers[i]->activateLayer(_current_activation_function,_layers[i-1]->_active_values,_layers[i-1]->_weights);
        }
    }




	//basic back propogation___________________________________________________________________________
	void backPropogation(Eigen::MatrixXd& right_answer)
	{
		_layers[_layers.size()-1]->_derivation_neurons = _current_loss_function->getDerivationLoss(_layers[_layers.size()-1]->_active_values, right_answer);

		for(long long i = _layers.size()-2; i >= 0; --i)
		{
			_layers[i]->calculateDerivation(_layers[i]->_weights, _layers[i+1]->_derivation_neurons, _layers[i+1]->_values, _layers[i]->_active_values, _current_activation_function);
		}
	}

    //predict___________________________________________________________________________
    Eigen::MatrixXd predict(Eigen::MatrixXd input){
        _layers[0]->_active_values = input;
        forwardFeed();
        return _layers[_layers.size()-1]->_active_values;
    }

    //сомнительно но okay
    void learn(Eigen::MatrixXd input,Eigen::MatrixXd right_answer,double learning_speed){
	      _layers[0]->_active_values = input;
	      forwardFeed();
	      backPropogation(right_answer);
	      for(int i = 0;i < _layers.size()-1;i++){
	    	 //_current_optimizer->updateWeights(_layers[i]->_weights,_layers[i]->_gradient,learning_speed);
		      _layers[i]->_weights -= learning_speed*_layers[i]->_gradient;
	      }
    }



  //WIP-----------------------------------------------------------------------------------------------

};

#endif

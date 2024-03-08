//
// Created by evgen on 06.03.2024.
//

#ifndef FENDL_DENSELAYER_HXX
#define FENDL_DENSELAYER_HXX

#include <Eigen/Dense>
#include <FenDL/Layer.hxx>


namespace FenDL{

class DenseLayer : public Layer{
private:
    typedef Eigen::MatrixXd Matrix;
    typedef Eigen::VectorXd Vector;

    Matrix Weights;
    Vector Bias;
    Matrix DerOfWeights;
    Vector DerOfBias;
    Matrix DerOfNeurons;
    Matrix Values;
    Matrix ActiveValues;
public:

    DenseLayer(const int prev_neurons_size,const int next_neurons_size): Layer(prev_neurons_size,next_neurons_size){}

    /*void init(){//!!!
        Weights.resize();
        Bias.resize();
        DerOfWeights.resize();
        DerOfBias.resize();
    }*/
    void ForwardProp(const Matrix& prev_layer_data){
        Values = Weights.transpose()*prev_layer_data + Bias;
        //ActivateFunction::Activate(Values,ActiveValues);
    }


};

}



#endif //FENDL_DENSELAYER_HXX

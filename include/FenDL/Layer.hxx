#ifndef FENDL_LAYER_HXX
#define FENDL_LAYER_HXX

#include <Eigen/Dense>
#include "Optimizer.hxx"

namespace FenDL{

class Layer {
protected:
    typedef Eigen::MatrixXd Matrix;
    typedef Eigen::VectorXd Vector;

    const int SizeOfLayerInput;
    const int SizeOfLayerOutput;

public:

    Layer(const int n,const int m): SizeOfLayerInput(n),SizeOfLayerOutput(m){}
    virtual ~Layer(){}

    int InputSize() const{
        return SizeOfLayerInput;
    }
    int OutputSize() const{
        return SizeOfLayerOutput;
    }
    virtual void init() = 0;

    virtual void ForwardProp(const Matrix& prev_layer_data) = 0;
    virtual const Matrix& output() const = 0;
    virtual void BackProp(const Matrix& prev_layer_data, const Matrix& next_layer_data) = 0;
    virtual const BackPropData() const = 0;
    virtual void UpdateWeights(Optimizer& opt) = 0;
    virtual Vector GetParameters() = 0;
    virtual void SetParameters(Vector& prm){};
    virtual Vector GetDerivatives() const = 0;
    virtual std::string LayerType() const = 0;
    virtual std::string ActivationType() const = 0;


};

}

#endif

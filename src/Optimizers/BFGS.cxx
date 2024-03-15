#include "FenDL/Optimizers/BFGS.hxx"

BFGS::BFGS(NeuralNetwork& network) : Optimizer(network){

    _inversed_hessian = new Matrixd[network._layers.size()];
    I = new Matrixd[network._layers.size()];
    _old_gradient = new Vector[network._layers.size()];
    _new_gradient = new Vector[network._layers.size()];
    _old_weights  = new Vector[network._layers.size()];
    _new_weights  = new Vector[network._layers.size()];
    y = new Vector[network._layers.size()];
    s = new Vector[network._layers.size()];
    ro = 0;

    for(int i  = 0;i < network._layers.size();++i)
    {
        _inversed_hessian[i] = Matrixd::Identity(network._layers[i]->_weights.size(),
                                                 network._layers[i]->_weights.size());

        I[i] =  _inversed_hessian[i];
        y[i] =  Vector::Zero(network._layers[i]->_weights.size());
        s[i] =  Vector::Zero(network._layers[i]->_weights.size());
        _old_gradient[i] = Vector::Zero(network._layers[i]->_weights.size());
        _new_gradient[i] = Vector::Zero(network._layers[i]->_weights.size());
        _old_weights[i]  = Vector::Zero(network._layers[i]->_weights.size());
        _new_weights[i]  = Vector::Zero(network._layers[i]->_weights.size());
    }

}
BFGS::~BFGS() {
    delete[] _inversed_hessian;
    delete[] _old_gradient;
    delete[] _new_gradient;
    delete[] _old_weights;
    delete[] _new_weights;
}
void BFGS::updateWeights(Matrixd answer,std::shared_ptr<LossFunction> _loss_function,double learning_speed = 0.5,double epoch = 1){
    for(int i = 0;i < _network._layers.size()-1;i++){
        _old_gradient[i] = Eigen::Map<Vector>(_network._layers[i]->_gradient.data(),
                                              _network._layers[i]->_gradient.size());

        _old_weights[i] = Eigen::Map<Vector>(_network._layers[i]->_weights.data(),
                                             _network._layers[i]->_weights.size());

        _new_weights[i] = _old_weights[i] - learning_speed*(_inversed_hessian[i]*_old_gradient[i]);

        _network._layers[i]->_weights = Eigen::Map<Matrixd>(_new_weights[i].data(),
                                                            _network._layers[i]->_weights.rows(),
                                                            _network._layers[i]->_weights.cols());

    }
    _network.forwardPropogation();
    backPropogation(answer,_loss_function);

    for(int i = 0;i < _network._layers.size()-1;i++){
        _new_gradient[i] = Eigen::Map<Vector>(_network._layers[i]->_gradient.data(),
                                              _network._layers[i]->_gradient.size());

        s[i] = _new_weights[i]-_old_weights[i];
        y[i] = _new_gradient[i]-_old_gradient[i];
        ro = 1 / y[i].dot(s[i]);
        _inversed_hessian[i] = (I[i] - ro*s[i]*y[i].transpose())*_inversed_hessian[i]*(I[i] - ro*y[i]*s[i].transpose()) + ro*s[i]*s[i].transpose();
    }
}
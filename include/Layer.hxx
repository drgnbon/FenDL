//
// Created by evgen on 06.03.2024.
//

#ifndef FENDL_LAYER_HXX
#define FENDL_LAYER_HXX

#include <Eigen>

using namespace Eigen;

class Layer {
public:
    size_t _size;
    MatrixXd active_values,values,gradient,weights;
};


#endif //FENDL_LAYER_HXX

#ifndef FENDL_LRELU_HXX
#define FENDL_LRELU_HXX

#include <FenDL/ActivateFunction.hxx>

namespace FenDL{
    class LReLU : ActivationFunction {
    public:
        double getActivateValue() override;
    };

}



#endif

#ifndef FENDL_RELU_HXX
#define FENDL_RELU_HXX

#include <FenDL/ActivateFunction.hxx>
namespace FenDL {
    class ReLU : public ActivationFunction {
    public:
        double getActivateValue() override;
    };

}
#endif

#ifndef FENDL_SIGMOID_HXX
#define FENDL_SIGMOID_HXX

#include <FenDL/ActivateFunction.hxx>
namespace FenDL {
    class Sigmoid : public ActivationFunction {
    public:
        double getActivateValue() override;
    };

}
#endif

#ifndef FENDL_THANGH_HXX
#define FENDL_THANGH_HXX

#include <FenDL/ActivateFunction.hxx>
namespace FenDL {
    class Thangh : ActivationFunction {
    public:
        double getActivateValue() override;
    };

}
#endif

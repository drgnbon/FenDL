#ifndef FENDL_CROSSENTROPY_HXX
#define FENDL_CROSSENTROPY_HXX

#include <FenDL/LossFunction.hxx>

class CrossEntropy : LossFunction
{
public:
    double getLoss() override;
};

#endif

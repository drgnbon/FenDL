#ifndef FENDL_CROSSENTROPY_HXX
#define FENDL_CROSSENTROPY_HXX

#include "LossFunction.hxx"

class CrossEntropy : LossFunction
{
public:
    double getLoss() override;
};

#endif

#ifndef FENDL_SQUAREERROR_HXX
#define FENDL_SQUAREERROR_HXX

#include "LossFunction.hxx"


class SquareError : public LossFunction {
public:
    double getLoss() override;
};

#endif

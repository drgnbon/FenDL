#ifndef FENDL_SQUAREERROR_HXX
#define FENDL_SQUAREERROR_HXX

#include <FenDL/LossFunction.hxx>

class SquareError : public LossFunction
{
public:
  double getMediumLoss(Matrixd active_value,Matrixd right_answer) override;

  Matrixd getDerivationLoss(Matrixd active_value,Matrixd right_answer) override;
};

#endif

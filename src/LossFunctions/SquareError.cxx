#include "FenDL/LossFunctions/SquareError.hxx"

#include <iostream>
double SquareError::getMediumLoss(Matrixd active_value,Matrixd right_answer)
{
    double SquareError = 0;
    for (int i = 0; i < active_value.rows(); ++i)
        for (int j = 0; j < active_value.cols(); ++j)
            SquareError += (active_value(i, j) - right_answer(i, j)) * (active_value(i, j) - right_answer(i, j));
    return SquareError;
}


Matrixd SquareError::getDerivationLoss(Matrixd active_value,Matrixd right_answer)
{
	return  2*(active_value-right_answer);
}

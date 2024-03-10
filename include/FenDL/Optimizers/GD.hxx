//
// Created by evgen on 06.03.2024.
//

#ifndef FENDL_GD_HXX
#define FENDL_GD_HXX

#include <FenDL/Optimizer.hxx>

class GD : public Optimizer {
public:
	void updateWeights(Eigen::MatrixXd& weights,Eigen::MatrixXd& gradient,double ls) override;
};


#endif //FENDL_GD_HXX

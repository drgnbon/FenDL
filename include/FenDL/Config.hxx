#ifndef FENDL_CONFIG_HXX
#define FENDL_CONFIG_HXX


//для Андрея это конфиг для самой либы это подключать ток в network;

//FenDl.hxx и этот файл должны быть идентичны на данном этапе, но нельзя путать подключение

#include <FenDL/Optimizer.hxx>
#include <FenDL/ActivateFunction.hxx>
#include <FenDL/LossFunction.hxx>
#include <FenDL/Layer.hxx>
#include <FenDL/NeuralNetwork.hxx>

#include <FenDL/Optimizers/ADAM.hxx>
#include <FenDL/Optimizers/BFGS.hxx>
#include <FenDL/Optimizers/GD.hxx>
#include <FenDL/ActivateFunctions/Sigmoid.hxx>
#include <FenDL/ActivateFunctions/Thangh.hxx>
#include <FenDL/LossFunctions/SquareError.hxx>
#include <FenDL/Layers/PerceptronLayer.hxx>

//typedef Eigen::MatrixXd Matrixd;
//typedef Eigen::MatrixXf Matrixf;
//typedef Eigen::MatrixXi Matrixi;


#endif

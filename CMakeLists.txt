cmake_minimum_required(VERSION 3.27)

project(FenDL)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(FenDL
        include/ActivateFunctions/LReLU.cxx
        include/ActivateFunctions/Sigmoid.cxx
        include/ActivateFunctions/Thangh.cxx
        include/Layer/ConvolutionalLayer.cxx
        include/Layer/DenseLayer.cxx
        include/Layer/PoolingLayer.cxx
        include/Layer/RecurrentLayer.cxx
        include/LossFunctions/CrossEntropy.cxx
        include/LossFunctions/SquareError.cxx
        include/NeuralNetwork/FunctionalModel.cxx
        include/NeuralNetwork/SequentionalModel.cxx
        include/Optimizer/ADAM.cxx
        include/Optimizer/BFGS.cxx
        include/Optimizer/BFP.cxx
        include/Optimizer/GD.cxx
        include/Optimizer/SGD.cxx
        include/ActivateFunctions/ReLU.cxx
        include/ActivateFunctions/ReLU.hxx
        include/ActivateFunctions/ELU.cxx
        include/ActivateFunctions/ELU.hxx
)

target_include_directories(FenDL PUBLIC
        include
        include/ActivateFunctions
        include/Layer
        include/LossFunctions
        include/NeuralNetwork
        include/Optimizer
)

add_executable(Main Main.cxx)

target_link_libraries(Main PRIVATE FenDL)

target_compile_features(FenDL PUBLIC cxx_std_23)

target_include_directories(FenDL PUBLIC
        "dependencies/eigen-3.4.0/Eigen"
)
target_include_directories(Main PRIVATE
        "dependencies/eigen-3.4.0/Eigen"
)

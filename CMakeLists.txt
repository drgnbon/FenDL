cmake_minimum_required(VERSION 3.15)

project(FenDL)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FenDL_headers_dir "${CMAKE_CURRENT_SOURCE_DIR}/include/FenDL")
set(FenDL_sources_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(FenDL_public_headers

  ${FenDL_headers_dir}/ActivateFunction.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Sigmoid.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Thangh.hxx
  ${FenDL_headers_dir}/ActivateFunctions/RELU.hxx

  ${FenDL_headers_dir}/Layer.hxx
  ${FenDL_headers_dir}/Layers/PerceptronLayer.hxx

  ${FenDL_headers_dir}/LossFunction.hxx
  ${FenDL_headers_dir}/LossFunctions/SquareError.hxx


  ${FenDL_headers_dir}/NeuralNetwork.hxx

  ${FenDL_headers_dir}/NeuralNetworks/FunctionalModel.hxx
  ${FenDL_headers_dir}/NeuralNetworks/SequentionalModel.hxx

  ${FenDL_headers_dir}/Optimizer.hxx
  ${FenDL_headers_dir}/Optimizers/ADAM.hxx
  ${FenDL_headers_dir}/Optimizers/BFGS.hxx
  ${FenDL_headers_dir}/Optimizers/GD.hxx

  ${FenDL_headers_dir}/FenDL.hxx

  ${FenDL_headers_dir}/Config.hxx
        
)

set(FenDL_sources
  ${FenDL_sources_dir}/ActivateFunctions/Sigmoid.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Thangh.cxx
  ${FenDL_sources_dir}/ActivateFunctions/RELU.cxx

  ${FenDL_sources_dir}/Layers/PerceptronLayer.cxx


  ${FenDL_sources_dir}/LossFunctions/SquareError.cxx


  ${FenDL_sources_dir}/NeuralNetworks/FunctionalModel.cxx
  ${FenDL_sources_dir}/NeuralNetworks/SequentionalModel.cxx

  ${FenDL_sources_dir}/Optimizers/ADAM.cxx
  ${FenDL_sources_dir}/Optimizers/BFGS.cxx
  ${FenDL_sources_dir}/Optimizers/GD.cxx

  ${FenDL_sources_dir}/NeuralNetwork.cxx
)

add_library(FenDL ${FenDL_public_headers} ${FenDL_sources})

target_include_directories(FenDL PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include;>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/eigen-3.4.0")
target_link_libraries(FenDL PUBLIC Eigen3::Eigen)

add_executable(Main Main.cxx)
target_link_libraries(Main PRIVATE FenDL)

#target_compile_features(FenDL PUBLIC cxx_std_23)
#target_include_directories(FenDL PUBLIC
#        "dependencies/eigen-3.4.0/Eigen"
#)
#target_include_directories(Main PRIVATE
#        "dependencies/eigen-3.4.0/Eigen"
#)

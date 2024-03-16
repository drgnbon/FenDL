cmake_minimum_required(VERSION 3.15)

project(FenDL)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FenDL_headers_dir "${CMAKE_CURRENT_SOURCE_DIR}/include/FenDL")
set(FenDL_sources_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(FenDL_public_headers

  ${FenDL_headers_dir}/ActivateFunction.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Sigmoid.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Th.hxx
  ${FenDL_headers_dir}/ActivateFunctions/ReLU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Linear.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Arctg.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Softsign.hxx
  ${FenDL_headers_dir}/ActivateFunctions/ISRU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/LReLU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/ELU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/SELU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/ISRLU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/SoftPlus.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Benti.hxx
  ${FenDL_headers_dir}/ActivateFunctions/SiLU.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Sin.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Sinc.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Gh.hxx
  ${FenDL_headers_dir}/ActivateFunctions/Arctg.hxx

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
  ${FenDL_headers_dir}/TrainerStrategy.hxx
  ${FenDL_headers_dir}/Branch.hxx
  ${FenDL_headers_dir}/Optimizers/Adagrad.hxx
  ${FenDL_headers_dir}/Optimizers/Adadelta.hxx
  ${FenDL_headers_dir}/Optimizers/RMSProp.hxx
)

set(FenDL_sources


  ${FenDL_sources_dir}/Layers/PerceptronLayer.cxx


  ${FenDL_sources_dir}/LossFunctions/SquareError.cxx


  ${FenDL_sources_dir}/NeuralNetworks/FunctionalModel.cxx
  ${FenDL_sources_dir}/NeuralNetworks/SequentionalModel.cxx

  ${FenDL_sources_dir}/Optimizers/ADAM.cxx
  ${FenDL_sources_dir}/Optimizers/BFGS.cxx
  ${FenDL_sources_dir}/Optimizers/GD.cxx

  ${FenDL_sources_dir}/NeuralNetwork.cxx

  ${FenDL_sources_dir}/TrainerStrategy.cxx
  ${FenDL_sources_dir}/Branch.cxx

  ${FenDL_sources_dir}/ActivateFunctions/Sigmoid.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Th.cxx
  ${FenDL_sources_dir}/ActivateFunctions/ReLU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Linear.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Arctg.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Softsign.cxx
  ${FenDL_sources_dir}/ActivateFunctions/ISRU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/LReLU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/ELU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/SELU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/ISRLU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/SoftPlus.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Benti.cxx
  ${FenDL_sources_dir}/ActivateFunctions/SiLU.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Sin.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Sinc.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Gh.cxx
  ${FenDL_sources_dir}/ActivateFunctions/Arctg.cxx
  ${FenDL_sources_dir}/Optimizer.cxx
  ${FenDL_sources_dir}/Optimizers/Adagrad.cxx
  ${FenDL_sources_dir}/Optimizers/Adadelta.cxx
  ${FenDL_sources_dir}/Optimizers/RMSProp.cxx

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

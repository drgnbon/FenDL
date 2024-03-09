# Install script for directory: D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/FenDL")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "D:/programs/CLion/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/AdolcForward"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/AlignedVector3"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/ArpackSupport"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/AutoDiff"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/BVH"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/EulerAngles"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/FFT"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/IterativeSolvers"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/KroneckerProduct"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/LevenbergMarquardt"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/MatrixFunctions"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/MoreVectorization"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/MPRealSupport"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/NonLinearOptimization"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/NumericalDiff"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/OpenGLSupport"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/Polynomials"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/Skyline"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/SparseExtra"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/SpecialFunctions"
    "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/Splines"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "D:/programming/FenDL/dependencies/eigen-3.4.0/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/programming/FenDL/cmake-build-debug/dependencies/eigen-3.4.0/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()


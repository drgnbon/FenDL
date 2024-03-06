cmake_minimum_required(3.10)
project(FenDl)
set(CMAKE_CXX_STANDARD 23)
add_executable(fendl Main.cxx)

target_link_libraries(my_executable PUBLIC FenDL.hxx)
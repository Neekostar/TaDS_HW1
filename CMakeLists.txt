cmake_minimum_required(VERSION 3.23)
project(TaDS_HW1)

set(CMAKE_CXX_STANDARD 23)

add_executable(TaDS_HW1 main.cpp CONSTANT.h Models/MyDouble.cpp Models/MyDouble.h Models/MyInt.cpp Models/MyInt.h Models/MyException.h Models/MyException.cpp)

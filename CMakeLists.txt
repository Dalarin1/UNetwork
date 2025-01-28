cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)

include_directories(include/Unet)
include_directories(include/)

project ("UNetwork")


add_executable (UNetwork "UNetwork.cpp" "UNetwork.h" "include/Unet/Neuron.h" "include/Unet/Functions.h" "include/Unet/Network.h")
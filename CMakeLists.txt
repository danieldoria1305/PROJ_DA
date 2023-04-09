cmake_minimum_required(VERSION 3.23)
project(ProjetoDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetoDA main.cpp Code/include/Station.h Code/include/LoadFiles.h Code/src/LoadFiles.cpp Code/src/Station.cpp Code/include/Network.h Code/src/Network.cpp Code/src/Graph.cpp Code/src/VertexEdge.cpp Code/src/App.cpp Code/include/Functions.h Code/src/Functions.cpp)

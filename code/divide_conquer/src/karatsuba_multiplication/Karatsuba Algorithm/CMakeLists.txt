CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(Karatsuba Algorithm)
SET(CMAKE_CXX_FLAGS " -D_GLIBCXX_USE_CXX11_ABI=0 -m32")
SET(CMAKE_CXX_STANDARD 11)
add_executable(NumerosGrandes main.cpp funcionesAuxiliares.cpp funcionesbajonivel.cpp Entero.cpp)


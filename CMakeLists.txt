cmake_minimum_required(VERSION 3.24)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto main.cpp Articulo.h HashMap.h HashEntry.h
        Funciones.h)

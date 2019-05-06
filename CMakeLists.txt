cmake_minimum_required(VERSION 3.13)
project(2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2 main.cpp Generacion.cpp Generacion.h GeneradorOleadas.cpp GeneradorOleadas.h GeneticManager.cpp
        GeneticManager.h Gladiator.cpp Gladiator.h Node.h PoolGladiadores.cpp PoolGladiadores.h LinkedList.h Poblacion.cpp Poblacion.h Simulacion.cpp Simulacion.h)
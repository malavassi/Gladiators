cmake_minimum_required(VERSION 3.14)
project(Gladiators)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5PrintSupport REQUIRED)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(Gladiators_SOURCES main.cpp mainwindow.cpp)
SET(Gladiators_HEADERS mainwindow.h)
SET(Gladiators_FORMS mainwindow.ui)

add_executable(Gladiators
        Generacion.cpp
        Generacion.h
        GeneradorOleadas.cpp
        GeneradorOleadas.h
        GeneticManager.cpp
        GeneticManager.h
        Gladiadores.ino
        Gladiator.cpp
        Gladiator.h
        LinkedList.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Node.h
        Plotting.pro
        Plotting.pro.user
        Poblacion.cpp
        Poblacion.h
        PoolGladiadores.cpp
        PoolGladiadores.h
        qcustomplot.cpp
        qcustomplot.h
        Simulacion.cpp
        Simulacion.h
        gladiador.png)

target_link_libraries(Gladiators Qt5::Widgets Qt5::PrintSupport)

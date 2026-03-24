cmake_minimum_required(VERSION 3.16)

project(devoir_2_collab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(devoir_2_collab main.cpp
    file.h file.cpp listeliee.cpp
    listeliee.h
    listelieenoeud.cpp
    listelieenoeud.h
    json.hpp
    pile.h pile.cpp
    fonctions_random.cpp)

include(GNUInstallDirs)
install(TARGETS devoir_2_collab
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

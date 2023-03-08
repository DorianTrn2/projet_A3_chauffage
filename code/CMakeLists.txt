cmake_minimum_required(VERSION 3.13)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code main.c consigne.txt autotests.c autotests.h consigne.c consigne.h define.h regulation.c regulation.h simulateur.c simulateur.h test_simulateur.c visualisationC.c visualisationC.h visualisationT.c visualisationT.h test_sim.c)
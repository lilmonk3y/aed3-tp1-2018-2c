cmake_minimum_required(VERSION 3.9)
project(tp1_gtest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp prueba_integracion_con_gtest/test/factorialTest.cpp prueba_integracion_con_gtest/src/factorial.cpp prueba_integracion_con_gtest/src/factorial.cpp prueba_integracion_con_gtest/src/factorial.h backtracking/test/BacktrackingTest.cpp backtracking/src/Backtracking.cpp backtracking/src/Backtracking.h  backtracking/src/Estrategia.h backtracking/src/EstrategiaFuerzaBruta.cpp backtracking/src/EstrategiaFuerzaBruta.h backtracking/src/EstrategiaBacktracking.cpp backtracking/src/EstrategiaBacktracking.h backtracking/test/BacktrackingPodasTest.cpp programacion_dinamica/test/ProgramacionDinamicaTest.cpp programacion_dinamica/src/ProgramacionDinamica.cpp programacion_dinamica/src/ProgramacionDinamica.h)
add_executable(tp1_gtest ${SOURCE_FILES})
target_link_libraries(tp1_gtest gtest gtest_main)

### executables ###

set(FUERZA_BRUTA_SRC backtracking/src/Backtracking.cpp backtracking/src/Backtracking.h  backtracking/src/Estrategia.h backtracking/src/EstrategiaFuerzaBruta.cpp backtracking/src/EstrategiaFuerzaBruta.h  execute_src/getInputMultipleSources-FB.cpp)
add_executable(FUERZA_BRUTA ${FUERZA_BRUTA_SRC})

set(BACKTRACKING_SRC backtracking/src/Backtracking.cpp backtracking/src/Backtracking.h  backtracking/src/Estrategia.h backtracking/src/EstrategiaBacktracking.cpp backtracking/src/EstrategiaBacktracking.h execute_src/getInputMultipleSources-BT.cpp)
add_executable(BACKTRACKING ${BACKTRACKING_SRC})

set(PROGRAMACION_DINAMICA_SRC programacion_dinamica/src/ProgramacionDinamica.h programacion_dinamica/src/ProgramacionDinamica.cpp execute_src/getInputMultipleSources-PD.cpp)
add_executable(PROGRAMACION_DINAMICA ${PROGRAMACION_DINAMICA_SRC})
cmake_minimum_required(VERSION 3.29)
project(graphingCalculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(graphingCalculator main.cpp graphingCalculator.cpp parser.cpp
        graphingCalculator.h)

set(SFML_DIR "/opt/homebrew/opt/sfml")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(graphingCalculator sfml-graphics sfml-window sfml-system)

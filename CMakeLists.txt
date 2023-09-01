cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Put Your .cpp files in line below
add_executable(spaceship src/main.cpp src/field.cpp src/space.cpp src/shiptype1.cpp src/shiptype2.cpp src/space_view.cpp src/spaceship.cpp src/menu.cpp)
target_include_directories(spaceship PUBLIC include)
target_link_libraries(spaceship ${CURSES_LIBRARIES})


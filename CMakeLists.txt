cmake_minimum_required (VERSION 3.10)

project ("Advent2025")

include_directories("include/iostream")

include(FetchContent)

FetchContent_Declare(
  glpk
  GIT_REPOSITORY https://github.com/Mizux/GLPK.git
  GIT_TAG        5.0.1
)

FetchContent_MakeAvailable(glpk)

add_executable (Advent2025Main "src/advent.cpp" "src/advent.h" "src/main.cpp")
target_link_libraries(Advent2025Main PRIVATE GLPK::GLPK)

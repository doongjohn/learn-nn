cmake_minimum_required(VERSION 3.24)

project(NeuralNetwork
  LANGUAGES CXX
)

# generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# linear algebra library
add_subdirectory(vendor/eigen)

# get all cpp source files
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(
  neural_network
  ${SRC_FILES})
target_compile_features(
  neural_network
  PRIVATE cxx_std_20)
target_include_directories(
  neural_network
  PRIVATE src/nn)
target_link_libraries(
  neural_network
  Eigen3::Eigen)

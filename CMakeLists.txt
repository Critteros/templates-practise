cmake_minimum_required(VERSION 3.15)

project(varadic LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")

include_directories("include")

file(GLOB sources "src/*.cpp")

add_compile_options(-Wextra -Wpedantic -Wshadow -Werror)
add_link_options(-fsanitize=address -fsanitize=leak)
add_executable(${PROJECT_NAME} ${sources})
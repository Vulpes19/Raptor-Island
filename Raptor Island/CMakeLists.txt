# CMakeList.txt : CMake project for Raptor Island

cmake_minimum_required (VERSION 3.8)


include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable (RaptorIsland ${SOURCES})

#SDL2
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

target_link_libraries(RaptorIsland PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
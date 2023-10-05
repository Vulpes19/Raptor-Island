# CMakeList.txt : CMake project for Raptor Island

cmake_minimum_required (VERSION 3.8)

set(SOURCES
    src/main.cpp
    src/ErrorHandler.cpp
    src/Game.cpp
    src/TextureManager.cpp
    src/GameObject.cpp
    src/Player.cpp
    src/InputDetector.cpp
    src/GameObjectFactory.cpp
    src/Vector.cpp
)

set(HEADERS
    include/Game.hpp
    include/ErrorHandler.hpp
    include/TextureManager.hpp
    include/GameObject.hpp
    include/Player.hpp
    include/InputObserver.hpp
    include/InputDetector.hpp
    include/GameObjectFactory.hpp
    include/Vector.hpp
)

include_directories(include)
#file(GLOB SOURCES "src/*.cpp")
add_executable (RaptorIsland ${SOURCES} ${HEADERS})

#SDL2
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

target_link_libraries(RaptorIsland PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
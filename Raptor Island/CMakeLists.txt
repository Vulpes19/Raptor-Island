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
    src/InputManager.cpp
    src/LevelBuilder.cpp
    src/Level.cpp
    src/FontManager.cpp
    src/UILabel.cpp
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
    include/InputManager.hpp
    include/LevelBuilder.hpp
    include/Level.hpp
    include/FontManager.hpp
    include/CollisionObserver.hpp
    include/UILabel.hpp
)

include_directories(include)
#file(GLOB SOURCES "src/*.cpp")
add_executable (RaptorIsland ${SOURCES} ${HEADERS})

#set(FREETYPE_DIR "C:/Users/asus/Documents/vcpkg/installed/x86-windows/share/freetype")
#freetype
find_package(Freetype REQUIRED)

#SDL2
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_link_libraries(RaptorIsland PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf Freetype::Freetype)
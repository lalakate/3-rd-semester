cmake_minimum_required(VERSION 3.26)
project(hui)

set(CMAKE_CXX_STANDARD 17)

add_executable(hui main.cpp
        AssetManager.cpp
        AssetManager.h
        Bird.cpp
        Bird.h
        Collision.cpp
        Collision.h
        DEFINITIONS.h
        Flash.cpp
        Flash.h
        Game.cpp
        Game.h
        GameOverState.cpp
        GameOverState.h
        GameState.cpp
        GameState.h
        HUD.cpp
        HUD.h
        InputManager.cpp
        InputManager.h
        Land.cpp
        Land.h
        MainMenuState.cpp
        MainMenuState.h
        Pipe.cpp
        Pipe.h
        SplashState.cpp
        SplashState.h
        State.h
        StateMachine.cpp
        StateMachine.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window network audio system REQUIRED)


include_directories(C:/SFML/include)
target_link_libraries(hui sfml-system sfml-window sfml-graphics sfml-audio ${SFML_DEPEDENCIES})
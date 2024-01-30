cmake_minimum_required(VERSION 3.26)
project(flappy_bird_course_work)

set(CMAKE_CXX_STANDARD 20)

add_executable(flappy_bird_course_work main.cpp
        Bird.cpp
        Bird.h
        AssetManager.cpp
        AssetManager.h
        defines.h
        State.h
        StateMachine.cpp
        StateMachine.h
        InputManager.cpp
        InputManager.h
        Game.cpp
        Game.h
        SplashState.cpp
        SplashState.h
        MainMenuState.cpp
        MainMenuState.h
        Pipe.cpp
        Pipe.h
        Collision.cpp
        Collision.h
        Flash.cpp
        Flash.h
        HUD.cpp
        HUD.h
        Land.cpp
        Land.h
        GameState.cpp
        GameState.h
        GameOverState.cpp
        GameOverState.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window network audio system REQUIRED)


include_directories(C:/SFML/include)
target_link_libraries(flappy_bird_course_work sfml-system sfml-window sfml-graphics sfml-audio ${SFML_DEPEDENCIES})
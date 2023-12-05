cmake_minimum_required(VERSION 3.7)
project(Pong VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_NAME Pong)

add_executable(
        ${EXECUTABLE_NAME}
        ${PROJECT_SOURCE_DIR}/Pong/AssetManager.cpp
        ${PROJECT_SOURCE_DIR}/Pong/Ball.cpp
        ${PROJECT_SOURCE_DIR}/Pong/Bot.cpp
        ${PROJECT_SOURCE_DIR}/Pong/Game.cpp
        ${PROJECT_SOURCE_DIR}/Pong/Main.cpp
        ${PROJECT_SOURCE_DIR}/Pong/Player.cpp
        ${PROJECT_SOURCE_DIR}/Pong/Score.cpp
)

target_include_directories(
        ${EXECUTABLE_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/SDL/include
        PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/SDL_Image/include
        PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/SDL_ttf/include
        PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/SDL_mixer/include
)

target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/SDL/lib/libSDL2-2.0.so
        PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/SDL_Image/lib/libSDL2_image.so
        PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/SDL_ttf/lib/libSDL2_ttf.so
        PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/SDL_mixer/lib/libSDL2_mixer.so
)
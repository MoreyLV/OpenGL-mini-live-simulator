cmake_minimum_required(VERSION 3.10)
project(TheGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Подтягиваем SFML из GitHub (соберётся вместе с проектом)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)

FetchContent_MakeAvailable(SFML)

# --- GLM (матрицы, вектора) ---
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

add_executable(TheGame
        src/main.cpp
        src/Shader.cpp
        include/Shader.h
        src/Mesh.cpp
        include/Mesh.h
        include/Vertices.h
        src/Utility.cpp
        include/Utility.h
        src/Camera.cpp
        include/Camera.h
        src/Events.cpp
        include/Events.h
        src/Rendering.cpp
        include/Rendering.h
        src/Map.cpp
        include/Map.h
        src/Vertices.cpp
        src/Simulation.cpp
        include/Simulation.h
)

target_sources(TheGame PRIVATE
        external/glad/src/glad.c
)

target_include_directories(TheGame PRIVATE
        external/glad/include
)

add_custom_command(TARGET TheGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_BINARY_DIR}/_deps/sfml-build/lib"
        "$<TARGET_FILE_DIR:TheGame>"

)

find_package(OpenGL REQUIRED)

target_link_libraries(TheGame
        PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        OpenGL::GL
        glm::glm
)

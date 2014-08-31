message ("Current Directory: ${CMAKE_CURRENT_BINARY_DIR}")

# versão mínima requerida do CMake
cmake_minimum_required (VERSION 2.8)

# nome do projeto
project (Pong)

# Versão da aplicação
set (MAJOR_VERSION 0)
set (MINOR_VERSION 1)
set (PATCH_VERSION 0)
set (VERSION \"${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}\")

# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# nome do executável
set (EXECUTABLE_NAME "game")

# Detecta e adiciona o SFML ao projeto
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package (SFML 2.1 REQUIRED system window graphics network audio)

message ("source dir: ${PROJECT_SOURCE_DIR}")
message ("binary dir: ${PROJECT_BINARY_DIR}")

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

include_directories (
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_BINARY_DIR}"
)

include_directories (
    "${PROJECT_SOURCE_DIR}/include"
)

add_subdirectory (include)

add_executable (${EXECUTABLE_NAME} main.cpp Game.cpp Ball.cpp Rectangle.cpp)

target_link_libraries (${EXECUTABLE_NAME} ${SFML_LIBRARIES})

install (TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

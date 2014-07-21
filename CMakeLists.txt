# versão mínima requerida do CMake
cmake_minimum_required (VERSION 2.8)

# nome do projeto
project (MajorTank)

# Versão da aplicação
set (MajorTank_MAJOR_VERSION 0)
set (MajorTank_MINOR_VERSION 1)
set (MajorTank_PATCH_VERSION 0)
set (MajorTank_VERSION \"${MajorTank_MAJOR_VERSION}.${MajorTank_MINOR_VERSION}.${MajorTank_PATCH_VERSION}\")

# nome do executável
set (EXECUTABLE_NAME "app")

# Detecta e adiciona o SFML ao projeto
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package (SFML 2.1 REQUIRED system window graphics network audio)

set (INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set (INSTALL_BIN_DIR bin CACHE_PATH "Installation directory for executables")
set (INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")

if (WIN32 AND NOT CYGWIN)
    set (DEF_INSTALL_CMAKE_DIR CMake)
else ()
    set (DEF_INSTALL_CMAKE_DIR lib/CMake/MajorTank)
endif ()

set (INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake Files")

# Faz com que caminhos relativos se tornem absolutos
foreach (p LIB BIN INCLUDE CMAKE)
    set (var INSTALL_${p}_DIR)
    if (NOT IS_ABSOLUTE "${${var}}")
        set (${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
    endif ()
endforeach ()

include_directories(
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_BINARY_DIR}")

add_subdirectory (game)

export (PACKAGE MajorTank)

file (RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
    "${INSTALL_INCLUDE_DIR}")

set (CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file (MajorTankConfig.cmake.in "${PROJECT_BINARY_DIR}/MajorTankConfig.cmake" @ONLY)

set (CONF_INCLUDE_DIRS "\${MAJORTANK_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file (MajorTankConfig.cmake.in "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MajorTankConfig.cmake" @ONLY)

configure_file (MajorTankConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/MajorTankConfigVersion.cmake" @ONLY)

install (FILES
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MajorTankConfig.cmake"
    "${PROJECT_BINARY_DIR}/MajorTankConfigVersion.cmake"
    DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install (EXPORT MajorTankTargets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

add_executable (${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)

install (TARGETS ${EXECUTABLE_NAME}
    EXPORT MajorTankTargets
    DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)

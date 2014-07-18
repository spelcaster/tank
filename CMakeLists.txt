cmake_minimum_required (VERSION 2.8)
project (MajorTank)

set (TANK_MAJOR_VERSION 1)
set (TANK_MINOR_VERSION 0)
set (TANK_PATCH_VERSION 0)
set (TANK_VERSION ${TANK_MAJOR_VERSION}.${TANK_MINOR_VERSION}.${TANK_PATCH_VERSION})

set (INSTALL_LIB_DIR lib CACHE PATH "")
set (INSTALL_BIN_DIR bin CACHE_PATH "")
set (INSTALL_INCLUDE_DIR include CACHE PATH "")

if (WIN32 AND NOT CYGWIN)
    set (DEF_INSTALL_CMAKE_DIR CMake)
else ()
    set (DEF_INSTALL_CMAKE_DIR lib/CMake/Tank)
endif ()

set (INSTALL_CMAKE_DIR ${DEV_INSTALL_CMAKE_DIR} CACHE PATH "")

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

add_subdirectory (tank)

export (TARGETS tank
    FILE "${PROJECT_BINARY_DIR}/TankTargets.cmake")

export (PACKAGES Tank)

file (RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")

set (CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${}")

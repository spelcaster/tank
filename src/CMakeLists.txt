add_library (game SHARED Game.cpp)

target_link_libraries (game ${SFML_LIBRARIES})

install (TARGETS game
    #IMPORTANTE - adicionando o executavel ao "export-set"
    EXPORT MajorTankTargets
    DESTINATION "${INSTALL_LIB_DIR}" COMPONENT lib)

install (FILES Game.hpp
    #IMPORTANTE - adicionando o executavel ao "export-set"
    EXPORT MajorTankTargets
    DESTINATION "${INSTALL_INCLUDE_DIR}" COMPONENT include)

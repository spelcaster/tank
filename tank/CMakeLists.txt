add_subdirectory (tank/libs)

configure_file (
    /home/hugocarmo/CPP/game/tank/libs/config.h
)
add_executable (main main.cxx)

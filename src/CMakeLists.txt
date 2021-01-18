target_sources($ENV{PROJECT_TITLE}
    PRIVATE
        main.cpp
        Game.cpp
        Util.cpp
)

add_subdirectory(Entities)
add_subdirectory(Managers)
add_subdirectory(Screens)
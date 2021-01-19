target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        main.cpp
        Game.cpp
        Util.cpp
)

add_subdirectory(Entities)
add_subdirectory(Managers)
add_subdirectory(Screens)
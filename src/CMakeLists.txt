# TODO: Rename template_proj if desired
add_executable(template_proj 
    main.cpp
    Game.cpp
    AssetManager.cpp
    CallbackManager.cpp
    DefaultScreen.cpp
    GameOverScreen.cpp
    GameScreen.cpp
    InputManager.cpp
    MainMenuScreen.cpp
    Pepe.cpp
    Pipe.cpp
    PipeManager.cpp
    StateManager.cpp
    Util.cpp
    )

target_link_libraries(
    template_proj
    PRIVATE project_options
            project_warnings
            CONAN_PKG::sfml
)
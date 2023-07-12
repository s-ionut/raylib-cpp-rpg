#include "App.hpp"

Application::Application(std::string window_name, int width, int height):
    _window_name(window_name),
    _width(width),
    _height(height),
    _window(width, height, window_name)
{
    #if defined(PLATFORM_WEB)
      emscripten_set_main_loop(Update, 0, 1);
    #else
      SetTargetFPS(_targeted_fps);
    #endif
};

Application::~Application()
{

};

// Main game loop
void Application::Execute()
{
    while (!_window.ShouldClose())    // Detect window close button or ESC key
    {
        Update();
        Draw();
    }
};

// Update
void Application::Update()
{
    //----------------------------------------------------------------------------------
    /// TODO: Update your variables here
    //----------------------------------------------------------------------------------
};

// Draw
void Application::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("raylib-rpg first window!", 160, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
};
#include "raylib-cpp.hpp"

#include "app/App.hpp"

int screenWidth  = 800;
int screenHeight = 450;

// Main Entry Point
int main()
{
  core::Application app("raylib-rpg", screenWidth, screenHeight);

  app.Execute();

  return 0;
}
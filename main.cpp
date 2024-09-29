#include "app/App.hpp"

int gScreenWidth  = 800;
int gScreenHeight = 450;

// Main Entry Point
int main()
{
  core::Application app("raylib-rpg", gScreenWidth, gScreenHeight);

  app.Execute();

  return 0;
}
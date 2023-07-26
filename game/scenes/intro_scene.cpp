#include "intro_scene.hpp"

using namespace game::scene;

IntroScene::IntroScene()
{
    /// TODO: Implement
}

void IntroScene::Update()
{
    //----------------------------------------------------------------------------------
    /// TODO: Update your variables here
    //----------------------------------------------------------------------------------
}

void IntroScene::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        raylib::DrawText("raylib-rpg IntroScene!", 160, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

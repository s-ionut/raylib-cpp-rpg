#include "mainScene.hpp"

using namespace game::scene;

MainScene::MainScene()
{
    /// TODO: Implement
}

void MainScene::Update()
{
    //----------------------------------------------------------------------------------
    /// TODO: Update your variables here
    //----------------------------------------------------------------------------------
}

void MainScene::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("raylib-rpg MainScene!", 160, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

#include "charCreationScene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
    /// TODO: Implement
}

void CharCreationScene::Update()
{
    //----------------------------------------------------------------------------------
    /// TODO: Update your variables here
    //----------------------------------------------------------------------------------
}

void CharCreationScene::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("raylib-rpg CharCreationScene!", 160, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

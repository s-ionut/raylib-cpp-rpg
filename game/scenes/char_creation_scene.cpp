#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
    /// TODO: Implement
    button = new core::gui::PushButton();
}

void CharCreationScene::Update()
{
    //----------------------------------------------------------------------------------
    /// TODO: Update your variables here
    //----------------------------------------------------------------------------------
    button->Update();
}

void CharCreationScene::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();
    button->Draw();
        ClearBackground(RAYWHITE);

        raylib::DrawText("raylib-rpg CharCreationScene!", 160, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

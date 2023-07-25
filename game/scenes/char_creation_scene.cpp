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
    count++ ;
    display_text = "raylib-rpg CharCreationScene!" + std::to_string(count);
}

void CharCreationScene::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();
    button->Draw();
        ClearBackground(RAYWHITE);

        raylib::DrawText(display_text, 160, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

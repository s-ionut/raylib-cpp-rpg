#include "renderer.hpp"

using namespace core::renderer;

Renderer::Renderer()
{
    _scene = new game::scene::IntroScene();
};

Renderer::~Renderer()
{
    delete _scene;
};

void Renderer::Update()
{
    GetScene();
    _scene->Update();
};

void Renderer::Draw()
{
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);

    _scene->Draw();

    EndDrawing();
    //----------------------------------------------------------------------------------
};

void Renderer::GetScene()
{
    scene::Scene* scene = _scene->GetScene();

    if(scene != nullptr)
    {
        delete _scene;
        _scene = scene;
    }
};
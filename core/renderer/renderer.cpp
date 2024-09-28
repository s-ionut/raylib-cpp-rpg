#include "renderer.hpp"

using namespace core::renderer;

Renderer::Renderer() { _scene = std::make_shared<game::scene::IntroScene>(); };

Renderer::~Renderer() {};

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

bool Renderer::Shutdown() { return _scene->Shutdown(); }

void Renderer::GetScene()
{
  std::shared_ptr<scene::Scene> scene = _scene->GetScene();

  if(scene != nullptr)
  {
    _scene = scene;
  }
};
#include "renderer.hpp"

using namespace core::renderer;

Renderer::Renderer()
{
  m_scene = std::make_shared<game::scene::IntroScene>();
};

Renderer::~Renderer() {};

void Renderer::Update()
{
  GetScene();
  m_scene->Update();
};

void Renderer::Draw()
{
  //----------------------------------------------------------------------------------
  BeginDrawing();
  ClearBackground(RAYWHITE);

  m_scene->Draw();

  EndDrawing();
  //----------------------------------------------------------------------------------
};

bool Renderer::Shutdown() { return m_scene->Shutdown(); }

void Renderer::GetScene()
{
  std::shared_ptr<scene::Scene> scene = m_scene->GetScene();

  if(scene != nullptr)
  {
    m_scene = scene;
  }
};
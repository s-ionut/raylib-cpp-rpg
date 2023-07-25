#include "scene_manager.hpp"

using namespace core::scene;

SceneManager::SceneManager()
{
    InitScene();
};

SceneManager::~SceneManager()
{
    delete _scene;
};

void SceneManager::InitScene()
{
    _scene = new game::scene::CharCreationScene();
};

Scene* SceneManager::Manage()
{
    if (IsKeyPressed(KEY_A))
    {
        return new game::scene::CharCreationScene();
    }
    else if (IsKeyPressed(KEY_B))
    {
        return new game::scene::MainScene();
    }

    return nullptr;
};

Scene* SceneManager::GetScene()
{
    Scene* currentScene = Manage();

    if (currentScene != nullptr)
    {
        delete _scene;
        _scene = currentScene;
    }

    return _scene;
};
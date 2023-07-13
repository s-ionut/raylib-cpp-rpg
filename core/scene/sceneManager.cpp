#include "sceneManager.hpp"

using namespace core::scene;

MainScene SceneManager::_mainScene;
CharCreationScene SceneManager::_charCreationScene;
Scene* SceneManager::_scene = nullptr;

SceneManager::SceneManager()
{
    InitScene();
};

SceneManager::~SceneManager()
{
    /// TODO: Implement
};

void SceneManager::InitScene()
{
    _scene = &_mainScene;
};

void SceneManager::Manage()
{
    if (IsKeyPressed(KEY_A))
    {
        _scene = &_charCreationScene;
    }
    else if (IsKeyPressed(KEY_B))
    {
        _scene = &_mainScene;
    }
};

Scene* SceneManager::GetScene()
{
    Manage();

    return _scene;
};
#include "map.hpp"
#include <iostream>

using namespace game::scene;

MapScene::MapScene() { m_scene = nullptr; }

MapScene::~MapScene() { std::cout << "Destroyed map scene" << std::endl; }

void MapScene::Update() {};

void MapScene::Draw() { raylib::DrawText("MAP!", 160, 200, 20, LIGHTGRAY); };

std::shared_ptr<core::scene::Scene> MapScene::GetScene() { return m_scene; }
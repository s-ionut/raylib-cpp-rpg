#include "bag.hpp"

using namespace game::scene;

BagScene::BagScene() { m_scene = nullptr; }

BagScene::~BagScene() { std::cout << "Destroyed bag scene" << std::endl; }

void BagScene::Update() {};

void BagScene::Draw() { raylib::DrawText("BAG!", 160, 200, 20, LIGHTGRAY); };

std::shared_ptr<core::scene::Scene> BagScene::GetScene() { return m_scene; }
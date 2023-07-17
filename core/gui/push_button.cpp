#include "push_button.hpp"

using namespace core::gui;

PushButton::PushButton():
    Button()
{

};

PushButton::PushButton(std::string texturePath, std::string fxPath, std::string fontPath):
    Button(texturePath, fxPath, fontPath)
{
    
};

PushButton::~PushButton()
{

};
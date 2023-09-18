#include "images.hpp"
#include <iostream>
using namespace core::gui;

CImage::CImage(std::string image_path, raylib::Vector2 position, raylib::Vector2 size)
{
    _image_path = image_path;
    _position = position;
    _size = size;

    _rectangle.SetPosition(_position);
    _rectangle.SetSize(_size);

    _image = std::make_shared<raylib::Texture2D>(GetWorkingDirectory() + _image_path);//.Load(_image_path);
    
};

CImage::CImage(raylib::Texture2D* image, raylib::Vector2 position, raylib::Vector2 size)
{
    _image.reset(image);

    _rectangle.SetPosition(_position);
    _rectangle.SetSize(_size);   
};

CImage::~CImage() { };

void CImage::Draw()
{
    _image->Draw(raylib::Rectangle(0, 0, _image->GetWidth(), _image->GetHeight()) ,_rectangle);
};
#include "images.hpp"
#include <iostream>
using namespace core::gui;

CImage::CImage(std::string     image_path,
               raylib::Vector2 position,
               raylib::Vector2 size)
{
  _image_path = image_path;
  _position   = position;
  _size       = size;

  _rectangle.SetPosition(_position);
  _rectangle.SetSize(_size);

  _image = raylib::Texture2D(GetWorkingDirectory() + _image_path);
};

CImage::CImage(raylib::Texture2D* image,
               raylib::Vector2    position,
               raylib::Vector2    size)
{
  _position = position;
  _size     = size;

  if(image == nullptr)
  {
    return;
  }

  _image.Load(*image);

  _rectangle.SetPosition(_position);
  _rectangle.SetSize(_size);
};

void CImage::updateImage(raylib::Texture2D* image) { _image.Load(*image); };

CImage::~CImage() {};

void CImage::Draw()
{
  _image.Draw(raylib::Rectangle(0,
                                0,
                                static_cast<float>(_image.GetWidth()),
                                static_cast<float>(_image.GetHeight())),
              _rectangle);
};
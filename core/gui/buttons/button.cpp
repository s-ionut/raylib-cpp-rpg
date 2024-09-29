#include "button.hpp"

using namespace core::gui;

Button::Button()
{
  m_fx      = std::make_shared<raylib::Sound>();
  m_font    = std::make_shared<text::CFont>();
  m_texture = std::make_shared<raylib::Texture>(getDefaultTexture("BUTTON"));

  loadCommonButtonSettings();
};

Button::Button(std::string name)
{
  m_fx      = std::make_shared<raylib::Sound>();
  m_font    = std::make_shared<text::CFont>();
  m_texture = std::make_shared<raylib::Texture>(getDefaultTexture(name));

  loadCommonButtonSettings();
}

Button::~Button() {};

Button::Button(std::string texturePath,
               std::string fxPath,
               std::string fontPath)
    : m_texturePath(texturePath)
    , m_fxPath(fxPath)
    , m_fontPath(fontPath)
{
  try
  {
    m_texture->Load(m_texturePath);
  }
  catch(const raylib::RaylibException& error)
  {
    TraceLog(LOG_WARNING, "Failed to load texture: %s", error.what());
  }

  try
  {
    m_fx->Load(m_fxPath);
  }
  catch(const raylib::RaylibException& error)
  {
    TraceLog(LOG_WARNING, "Failed to load sound: %s", error.what());
  }

  m_font = std::make_shared<text::CFont>(m_fontPath);

  loadCommonButtonSettings();
};

raylib::Texture Button::getDefaultTexture(std::string text)
{
  // Create basic texture with nothing in it, just to not throw an error
  Vector2 textSize = m_font->MeasureText(
    text, m_font->getFontSize(), m_font->getFontSpacing());
  const int          barHeight = static_cast<int>(textSize.y) + 20;
  const int          barWidth  = static_cast<int>(textSize.x) + 10;
  std::vector<Color> colors    = {DARKGRAY, LIGHTGRAY, WHITE};
  Image              image     = GenImageColor(
    barWidth, static_cast<int>(colors.size()) * barHeight, BLACK);

  for(int i = 0; i < colors.size(); ++i)
  {
    Rectangle rec = {0,
                     static_cast<float>(i * barHeight),
                     static_cast<float>(barWidth),
                     static_cast<float>(barHeight)};
    ImageDrawRectangleRec(&image, rec, colors[i]);
  }

  Texture2D defaultTexture = LoadTextureFromImage(image);

  UnloadImage(image);

  return defaultTexture;
};

void Button::loadCommonButtonSettings()
{
  m_numFrames   = static_cast<int>(ButtonState::COUNT);
  m_frameHeight = m_texture->height / static_cast<float>(m_numFrames);

  m_sourceRec = raylib::Rectangle(.0f,
                                  .0f,
                                  static_cast<float>(m_texture->width),
                                  static_cast<float>(m_frameHeight));

  m_state = ButtonState::NOT_PRESSED;
};
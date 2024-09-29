#include "text_box.hpp"

using namespace core::gui;

TextBox::TextBox()
    : m_timer()
{
  m_fx      = std::make_shared<raylib::Sound>();
  m_font    = std::make_shared<text::CFont>();
  m_texture = std::make_shared<raylib::Texture>(getDefaultTexture());

  m_inputText = "placeholder";
  loadCommonTextBoxSettings();

  move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

TextBox::TextBox(std::string text)
    : m_timer()
{
  m_fx      = std::make_shared<raylib::Sound>();
  m_font    = std::make_shared<text::CFont>();
  m_texture = std::make_shared<raylib::Texture>(getDefaultTexture());

  m_inputText = text;
  loadCommonTextBoxSettings();

  move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

TextBox::~TextBox() {};

TextBox::TextBox(std::string texture_path,
                 std::string fx_path,
                 std::string font_path)
    : m_texturePath(texture_path)
    , m_fxPath(fx_path)
    , m_fontPath(font_path)
    , m_timer()
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

  try
  {
    m_font->Load(m_fontPath);
  }
  catch(const raylib::RaylibException& error)
  {
    TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
  }

  loadCommonTextBoxSettings();
};

void TextBox::Update()
{

  if(isActive())
  {
    // Get char pressed (unicode character) on the queue
    int key = GetCharPressed();

    // Check if more characters have been pressed on the same frame
    while(key > 0)
    {
      // NOTE: Only allow keys in range [32..125]
      if((key >= 32) && (key <= 125))
      {
        m_inputText.push_back(static_cast<char>(key));
      }

      key = GetCharPressed(); // Check next character in the queue
    }

    if(IsKeyPressed(KEY_BACKSPACE))
    {
      if(m_inputText.size() > 0)
        m_inputText.pop_back();
    }

    if(IsKeyPressed(KEY_ENTER))
    {
      // TODO: do something with it
      std::cout << m_inputText << std::endl;
    }

    cursorBlink();
  }

  setOutputText();
};

void TextBox::Draw()
{
  Vector2 textPos;

  // Get the button texture source coordinates
  m_sourceRec.y = static_cast<int>(m_state) * m_frameHeight;

  // Draw the textbox texture
  m_texture->Draw(m_sourceRec,
                  raylib::Vector2(m_bounds.x, m_bounds.y),
                  raylib::Color::White());

  // Render text to H:center / V:center by default
  textPos.x
    = (m_bounds.x + (m_bounds.width / 2))
      - (m_font->MeasureText(
           m_outputText, m_font->getFontSize(), m_font->getFontSpacing()))
            .x
          / 2.0f;
  textPos.y
    = (m_bounds.y + (m_bounds.height / 2))
      - (m_font->MeasureText(
           m_outputText, m_font->getFontSize(), m_font->getFontSpacing()))
            .y
          / 2.0f;

  // Draw the text on the button texture
  m_font->DrawText(m_outputText,
                   textPos,
                   m_font->getFontSize(),
                   m_font->getFontSpacing(),
                   raylib::Color::Red());
};

bool TextBox::isActive()
{
  raylib::Mouse   mouse;
  raylib::Vector2 position = mouse.GetPosition();

  if(!m_bounds.CheckCollision(position))
  {
    if(mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
    {
      m_state = TextBoxState::NOT_ACTIVE;
    }
  }
  else
  {
    if(mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
    {
      m_state = TextBoxState::ACTIVE;
    }
  }

  return (m_state == TextBoxState::ACTIVE);
};

void TextBox::cursorBlink()
{
  if(m_state == TextBoxState::ACTIVE && !m_timer.hasTimePassedMS(400))
    return;

  if(m_outputText.back() != '|')
  {
    m_outputText.append("|");
  }
  else
  {
    m_outputText.pop_back();
  }

  m_timer.refresh();
};

void TextBox::setOutputText()
{
  if(m_outputText.size() && m_outputText.back() == '|')
    m_outputText = m_inputText + "|";
  else
    m_outputText = m_inputText;

  if(!m_outputText.size())
  {
    m_outputText = "-";
  }
};

void TextBox::move(raylib::Vector2 updated_position)
{
  raylib::Vector2 positionToUpdate
    = raylib::Vector2(updated_position.x - m_texture->width / 2.0f,
                      updated_position.y - m_texture->height / 2.0f);
  raylib::Vector2 size
    = raylib::Vector2(static_cast<float>(m_texture->width), m_frameHeight);

  m_bounds.SetPosition(positionToUpdate);
  m_bounds.SetSize(size);
};

raylib::Texture TextBox::getDefaultTexture()
{
  // Create basic texture with nothing in it, just to not throw an error
  const int          barHeight = 30;
  const int          barWidth  = 130;
  std::vector<Color> colors    = {BLUE, SKYBLUE};
  Image              image     = GenImageColor(
    barWidth, static_cast<int>(colors.size()) * barHeight, BLACK);

  for(size_t i = 0; i < colors.size(); ++i)
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

std::string TextBox::getText() { return m_inputText; };

void TextBox::loadCommonTextBoxSettings()
{
  m_numFrames   = static_cast<int>(TextBoxState::COUNT);
  m_frameHeight = m_texture->height / static_cast<float>(m_numFrames);

  m_sourceRec = raylib::Rectangle(.0f,
                                  .0f,
                                  static_cast<float>(m_texture->width),
                                  static_cast<float>(m_frameHeight));

  m_state = TextBoxState::NOT_ACTIVE;
};
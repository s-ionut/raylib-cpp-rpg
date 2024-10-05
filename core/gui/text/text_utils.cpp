#include "text_utils.hpp"

int core::text::centerTextToMiddleScreen(std::string text, int fontSize)
{
  return GetScreenWidth() / 2 - (MeasureText((text).c_str(), fontSize) / 2);
}
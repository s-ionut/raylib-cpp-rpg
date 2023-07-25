#ifndef _CHAR_CREATION_SCENE_HPP
#define _CHAR_CREATION_SCENE_HPP

#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"
#include <string>
namespace game{
    namespace scene{
        class CharCreationScene: public core::scene::Scene
        {
            public:
                CharCreationScene();
                virtual ~CharCreationScene() {};
                virtual void Update();
                virtual void Draw();

            private:
                int count = 0;
                std::string display_text;
                core::gui::PushButton* button;
        };
    } // namespace scene
} // namespace game

#endif // _CHAR_CREATION_SCENE_HPP
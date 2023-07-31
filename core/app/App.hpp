#pragma once

#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "renderer/renderer.hpp"

namespace core{
    class Application
    {
        public:
            Application(std::string _window_name, int _width, int _height);
            ~Application();

            void Execute();

        private:
            raylib::Window _window;                     // Context window
            raylib::AudioDevice _audio_device;          // Audio device
            scene::Scene* _scene;                       // Scene to display
            std::string _window_name = "Application";   // Window name
            renderer::Renderer _renderer;               // Renderer to display scenes
            int _width = 800;                           // Window width
            int _height = 600;                          // Window height

            int _targeted_fps = 60;                     // Targeted FPS
    };
} // namespace core

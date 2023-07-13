#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "scene/sceneManager.hpp"

namespace Core{
    class Application
    {
        public:
        Application(std::string _window_name, int _width, int _height);
        ~Application();

        void Execute();

        private:
        void Update();
        void Draw();
        // void handleInput();

        raylib::Window _window;
        Scene _scene;
        std::string _window_name = "Application";
        int _width = 800;
        int _height = 600;

        int _targeted_fps = 60;
    };
} // Core
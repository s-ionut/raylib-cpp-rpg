#pragma once

// system specific
#include "core/etc/system_includes.h"

namespace game {
    namespace manager {
        class ResourceManager {
            private:
                // Singleton instance
                static ResourceManager* _instance;

                // Directory tracking
                std::set<std::string> _currentFiles;
                std::string _directory;
                std::map<std::string, std::any> _storage;

                ResourceManager(const std::string& dir);
                void UpdateFileList();
                void StartPeriodicCheck();

            public:
                // Singleton get instance method
                static ResourceManager* GetInstance(const std::string& dir);
                static ResourceManager* GetInstance();

                template <typename T>
                T* GetResource(const std::string& resourceName)
                {
                    std::cout << "Trying to get the " << resourceName << " resource" << std::endl;

                    if (_currentFiles.find(resourceName) == _currentFiles.end())
                    {
                        return nullptr;    
                    }

                    if (_storage.find(resourceName) != _storage.end())
                    {
                        return std::any_cast<T*>(_storage[resourceName]);
                    }

                    T* resource = nullptr;

                    if constexpr (std::is_same_v<T, raylib::Texture2D>)
                    {
                        resource = new raylib::Texture2D(resourceName);//LoadTexture2D(resourceName);
                    }
                    else if constexpr (std::is_same_v<T, int>)
                    {
                        //resource = LoadSound(resourceName);
                    }
                    else if constexpr (std::is_same_v<T, std::string>)
                    {
                        //resource = LoadImage(resourceName);
                    }

                    if (resource) {
                        _storage[resourceName] = resource;
                    }

                    return resource;
                };
        };
    } // namespace manager
} // namespace game
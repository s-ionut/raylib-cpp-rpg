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
                std::filesystem::path _directory;
                std::map<std::string, std::any> _storage;

                ResourceManager(const std::string& dir);
                void UpdateFileList();
                void StartPeriodicCheck();
                void RecursiveScanDirectory(const std::filesystem::path& directory, std::set<std::string>& files) const;
                const std::string findResourceInPaths(const std::string& resourceName);

            public:
                // Singleton get instance method
                static ResourceManager* GetInstance(const std::string& dir);
                static ResourceManager* GetInstance();

                template <typename T>
                T* GetResource(const std::string& resourceName)
                {
                    std::string pathInFiles = findResourceInPaths(resourceName);

                    if (pathInFiles.empty())
                    {
                        return nullptr;    
                    }

                    if (_storage.find(pathInFiles) != _storage.end())
                    {
                        return std::any_cast<T*>(_storage[pathInFiles]);
                    }

                    T* resource = nullptr;

                    if constexpr (std::is_same_v<T, raylib::Texture2D>)
                    {
                        resource = new raylib::Texture2D(pathInFiles);
                    }
                    else if constexpr (std::is_same_v<T, int>)
                    {
                        //resource = LoadSound(pathInFiles);
                    }
                    else if constexpr (std::is_same_v<T, std::string>)
                    {
                        //resource = LoadImage(pathInFiles);
                    }

                    if (resource) {
                        _storage[pathInFiles] = resource;
                    }

                    return resource;
                };
        };
    } // namespace manager
} // namespace game
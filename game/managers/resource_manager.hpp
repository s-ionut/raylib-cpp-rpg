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

                ResourceManager(const std::string& dir);
                void UpdateFileList();
                void StartPeriodicCheck();

            public:
                // Singleton get instance method
                static ResourceManager* GetInstance(const std::string& dir);
                static ResourceManager* GetInstance();

                template <typename T>
                T* GetResource(const std::string& resourceName);
        };
    } // namespace manager
} // namespace game
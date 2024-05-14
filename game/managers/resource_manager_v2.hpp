#pragma once

// system specific
#include "core/etc/system_includes.h"

namespace game {
    namespace manager {
        class ResourceManagerV2 {
            private:
                // Singleton instance
                static ResourceManagerV2* _instance;

                // Directory tracking
                std::set<std::string> _currentFiles;
                std::filesystem::path _directory;
                std::map<std::string, std::any> _storage;

                ResourceManagerV2(const std::string& dir);

            public:
                // Singleton get instance method
                static ResourceManagerV2* getInstance(const std::string& dir);
                static ResourceManagerV2* getInstance();
        };
    } // namespace manager
} // namespace game
#include "resource_manager.hpp"

using namespace game::manager;

ResourceManager* ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager(const std::string& dir) : _directory(dir)
{
    UpdateFileList();
    StartPeriodicCheck();
};

void ResourceManager::UpdateFileList()
{
    _currentFiles.clear();
    for (const auto& entry : std::filesystem::directory_iterator(_directory))
    {
        _currentFiles.insert(entry.path().string());
    }
};

void ResourceManager::StartPeriodicCheck() {
    std::thread([this]() {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::set<std::string> newFiles;
            for (const auto& entry : std::filesystem::directory_iterator(_directory))
            {
                newFiles.insert(entry.path().string());
            }

            for (const auto& file : newFiles)
            {
                if (_currentFiles.find(file) == _currentFiles.end())
                {
                    std::cout << "File added: " << file << std::endl;
                }
            }

            for (const auto& file : _currentFiles)
            {
                if (newFiles.find(file) == newFiles.end())
                {
                    std::cout << "File removed: " << file << std::endl;
                }
            }

            _currentFiles = newFiles;
        }
    }).detach();
};

ResourceManager* ResourceManager::GetInstance(const std::string& dir)
{
    if (!_instance)
    {
        _instance = new ResourceManager(dir);
    }
    return _instance;
};

ResourceManager* ResourceManager::GetInstance()
{
    if (!_instance)
    {
        throw std::runtime_error("ResourceManager instance not yet created with directory.");
    }
    return _instance;
};

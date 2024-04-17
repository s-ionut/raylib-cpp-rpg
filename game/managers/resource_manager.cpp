#include "resource_manager.hpp"

using namespace game::manager;

ResourceManager* ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager(const std::string& dir) : _directory(dir)
{
    updateFileList();
    startPeriodicCheck();
};

void ResourceManager::updateFileList()
{
    _currentFiles.clear();
    recursiveScanDirectory(_directory, _currentFiles);
};

void ResourceManager::startPeriodicCheck() {
    std::thread([this]() {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::set<std::string> newFiles;
            recursiveScanDirectory(_directory, newFiles);

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

void ResourceManager::recursiveScanDirectory(const std::filesystem::path& directory, std::set<std::string>& files) const {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory))
    {
        if (std::filesystem::is_regular_file(entry))
        {
            files.insert(entry.path().string());
        }
    }
};

const std::string ResourceManager::findResourceInPaths(const std::string& resourceName)
{
    for (const std::string& filePath : _currentFiles)
    {
        if (filePath.find(resourceName) != std::string::npos)
        {
            return filePath;
        }
    }
    return "";
};

ResourceManager* ResourceManager::getInstance(const std::string& dir)
{
    if (!_instance)
    {
        _instance = new ResourceManager(dir);
    }
    return _instance;
};

ResourceManager* ResourceManager::getInstance()
{
    if (!_instance)
    {
        throw std::runtime_error("ResourceManager instance not yet created with directory.");
    }
    return _instance;
};

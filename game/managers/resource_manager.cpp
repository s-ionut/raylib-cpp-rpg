#include "resource_manager.hpp"

using namespace game::manager;

ResourceManager* ResourceManager::m_instance = nullptr;

ResourceManager::ResourceManager(
  const std::initializer_list<std::filesystem::path> paths)
{
  for(const auto& path : paths)
  {
    if(m_directory.empty())
    {
      m_directory = path;
    }
    else
    {
      m_directory /= path;
    }
  }

  updateFileList();
  startPeriodicCheck();
};

void ResourceManager::updateFileList()
{
  m_currentFiles.clear();
  recursiveScanDirectory(m_directory, m_currentFiles);
};

void ResourceManager::startPeriodicCheck()
{
  std::thread([this]() {
    while(true)
    {
      std::this_thread::sleep_for(std::chrono::seconds(1));

      std::set<std::string> newFiles;
      recursiveScanDirectory(m_directory, newFiles);

      for(const auto& file : newFiles)
      {
        if(m_currentFiles.find(file) == m_currentFiles.end())
        {
          std::cout << "File added: " << file << std::endl;
        }
      }

      for(const auto& file : m_currentFiles)
      {
        if(newFiles.find(file) == newFiles.end())
        {
          std::cout << "File removed: " << file << std::endl;
        }
      }

      m_currentFiles = newFiles;
    }
  }).detach();
};

void ResourceManager::recursiveScanDirectory(
  const std::filesystem::path& directory, std::set<std::string>& files) const
{
  for(const auto& entry :
      std::filesystem::recursive_directory_iterator(directory))
  {
    if(std::filesystem::is_regular_file(entry))
    {
      files.insert(entry.path().string());
    }
  }
};

const std::string
ResourceManager::findResourceInPaths(const std::string& resourceName)
{
  for(const std::string& filePath : m_currentFiles)
  {
    if(filePath.find(resourceName) != std::string::npos)
    {
      return filePath;
    }
  }
  return "";
};

ResourceManager* ResourceManager::getInstance(
  const std::initializer_list<std::filesystem::path> paths)
{
  if(!m_instance)
  {
    m_instance = new ResourceManager(paths);
  }
  return m_instance;
};

ResourceManager* ResourceManager::getInstance()
{
  if(!m_instance)
  {
    throw std::runtime_error(
      "ResourceManager instance not yet created with directory.");
  }
  return m_instance;
};

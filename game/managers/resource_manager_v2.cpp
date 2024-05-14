#include "resource_manager_v2.hpp"

using namespace game::manager;

ResourceManagerV2* ResourceManagerV2::_instance = nullptr;

ResourceManagerV2::ResourceManagerV2(const std::string& dir) : _directory(dir)
{
    //TODO: implement the fucking concept of the new resource manager;
    //      concept so far is:
    //          - it should have a map to different resource and files that contains them
    //          - it should have a type that contains the texture along a UID for textures
    //          - it should have a getter for every type of resource (i.e. getCharactersTexture(), getUiTextures())
    //            where it should return the full texture files converted to raylib texture
    //          - it should have getter by UID of the texture and return only one texture



    //          - maybe down the road expand to Sound, have it save, load, reload data etc...
};

ResourceManagerV2* ResourceManagerV2::getInstance(const std::string& dir)
{
    if (!_instance)
    {
        _instance = new ResourceManager(dir);
    }
    return _instance;
};

ResourceManagerV2* ResourceManagerV2::getInstance()
{
    if (!_instance)
    {
        throw std::runtime_error("ResourceManager instance not yet created with directory.");
    }
    return _instance;
};
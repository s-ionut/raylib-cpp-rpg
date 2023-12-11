#include "serializable.hpp"

using namespace core::serialization;

std::string getObjectType(std::istream& in)
{
    char typeBuffer[256];
    in.getline(typeBuffer, 256, '\0');
    std::string type(typeBuffer);

    return type;
}

template<typename T>
std::unique_ptr<T> deserializeObject(std::istream& in)
{
    static_assert(std::is_base_of<Serializable, T>::value, "T must be derived from Serializable");

    std::string type;
    std::getline(in, type, '\0'); // Read type identifier

    if (type != T::classType()) {
        throw std::runtime_error("Type mismatch during deserialization");
    }

    auto obj = std::make_unique<T>(); // Using smart pointers for memory management
    obj->deserialize(in);
    return obj;
}

void serializeObject(const Serializable& obj, std::ostream& out)
{
    std::string type = obj.getType();
    out.write(type.c_str(), type.size() + 1);  // Including the null terminator
    obj.serialize(out);
}

std::ifstream getLoadFile(const std::string& filename)
{
    if (!std::filesystem::exists(filename)) {
        std::cout << "File does not exist." << std::endl;
        return;
    }

    std::ifstream inFile(filename, std::ios::binary | std::ios::in);

    if (!inFile) {
        throw std::runtime_error("Unable to open file for reading.");
    }

    return inFile;
}

std::ofstream getSaveFile(const std::string& filename)
{
    std::ofstream outFile(filename, std::ios::binary | std::ios::out);

    if (!outFile) {
        throw std::runtime_error("Unable to open file for writing.");
    }

    return outFile;
}
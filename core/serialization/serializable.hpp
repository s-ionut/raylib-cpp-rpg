#pragma once

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace serialization {
        class Serializable {
            public:
                virtual void serialize(std::ostream& out) const = 0;
                virtual void deserialize(std::istream& in) = 0;
                virtual std::string getType() const = 0;
            };

        template <typename Derived>
        class SerializableBase : public Serializable {
        public:
            static std::string classType() {
                return typeid(Derived).name();
            }

            std::string getType() const override {
                return classType();
            }
        };

    std::pair<Serializable*, std::string> deserializeObject(std::istream& in);
    void serializeObject(const Serializable& obj, std::ostream& out);
    std::ifstream getLoadFile(const std::string& filename);
    std::ofstream getSaveFile(const std::string& filename);
    } // namespace serialization
} // namespace core
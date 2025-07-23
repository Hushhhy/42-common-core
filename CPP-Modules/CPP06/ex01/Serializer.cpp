#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copy) {
    (void)copy;
}

Serializer &Serializer::operator=(const Serializer &copy) {
    (void)copy;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t   Serializer::serialize(Data* ptr) {
    return static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return static_cast<Data*>(reinterpret_cast<Data*>(raw));
}
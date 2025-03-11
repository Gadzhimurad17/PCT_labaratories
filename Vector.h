#include <iostream>
namespace{
    const size_t kDefaultSize=8;
    const size_t grownFactor=2;
}
class Vector{
    public:
        size_t vectorSize{};
        size_t vectorCapacity{};
        int* vector{};
};
[[nodiscard]] Vector CreateVector();
void DeleteVector(Vector& vector);

[[nodiscard]] int& GetElement(Vector& vector, size_t index);
void PushBack(Vector& vector, int element);

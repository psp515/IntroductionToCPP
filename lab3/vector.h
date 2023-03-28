#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // std::size_t
#include <memory>  // std::unique_ptr
#include "fraction.h"


class Vector
{

public:
    explicit Vector(size_t capacity = defaultCapacity)
    : data_(std::make_unique<Fraction[]>(capacity)), size_(0), capacity_(capacity) {}

    Vector(Vector const &toCopy)
    : data_(std::make_unique<Fraction[]>(toCopy.capacity_)), size_(toCopy.size_), capacity_(toCopy.capacity_)
    {
        for (size_t i = 0; i < toCopy.size_; i++)
            this->data_[i] = toCopy.data_[i];
    }

    Vector(Vector && vector) noexcept : data_(std::move(vector.data_)), size_(vector.size_), capacity_(vector.capacity_)
    {
        vector.data_ = nullptr;
        vector.size_ = 0;
        vector.capacity_ = 0;
    }

    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t capacity() const;
    [[nodiscard]] Fraction* data() const;

    Vector& operator=(const Vector &toCopy);
    Vector& operator=(Vector &&toCopy) noexcept ;

    Fraction operator[](size_t index);

    Fraction operator[](size_t index) const;

    void push_back(Fraction fraction);

private:

    std::unique_ptr<Fraction[]> data_;
    std::size_t size_{};
    std::size_t capacity_;

    static constexpr size_t defaultCapacity = 0;
};

#endif // VECTOR_H

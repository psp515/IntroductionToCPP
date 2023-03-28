// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()

#include "vector.h"


size_t Vector::size() const {
    return this->size_;
}

size_t Vector::capacity() const {
    return this->capacity_;
}

Fraction *Vector::data() const {
    return this->data_.get();
}

Vector& Vector::operator=(const Vector &toCopy) {

    if (this != &toCopy) {
        size_ = toCopy.size_;
        capacity_ = toCopy.capacity_;
        data_ = std::make_unique<Fraction[]>(toCopy.capacity_);

        for (size_t i = 0; i < toCopy.size_; i++)
            this->data_[i] = toCopy.data_[i];
    }

    return *this;
}

void Vector::push_back(Fraction fraction) {
    if(this->capacity_ == this->size_)
    {
        capacity_++;

        auto new_data = std::make_unique<Fraction[]>(capacity_);
        for (size_t i = 0; i < size_; i++)
            new_data[i] = data_[i];

        data_ = std::move(new_data);
    }

    this->data_[this->size_] = fraction;
    this->size_ +=1 ;
}

Fraction Vector::operator[](size_t index) {
    if(index >= this->size_)
        throw std::out_of_range("Vector contains less elements.");
    return this->data_[index];
}

Fraction Vector::operator[](size_t index) const {
    if(index >= this->size_)
        throw std::out_of_range("Vector contains less elements.");
    return this->data_[index];
}

Vector &Vector::operator=(Vector &&toCopy) noexcept{
    if (this != &toCopy) {
        size_ = toCopy.size_;
        capacity_ = toCopy.capacity_;
        data_ = std::move(toCopy.data_);

        toCopy.size_ = 0;
        toCopy.capacity_ = 0;
        toCopy.data_ = nullptr;
    }

    return *this;
}

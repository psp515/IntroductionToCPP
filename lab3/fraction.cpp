#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric>   // std::gcd

#include "fraction.h"

int Fraction::numerator() const {
    return this->numerator_;
}

void Fraction::setNumerator(int numerator) {
    this->numerator_ = numerator;
}

int Fraction::denominator() const {
    return this->denominator_;
}

void Fraction::setDenominator(int denominator) {

    if (denominator == invalidDenominatorValue)
        throw std::invalid_argument("Denominator cannot be 0. 4r3 Y0U Cr4zY?");

    this->denominator_ = denominator;
}

Fraction Fraction::operator*(const Fraction &f_1) const {
    int num = this->numerator_ * f_1.numerator_;
    int denom = this->denominator_ * f_1.denominator_;

    if (denom == invalidDenominatorValue)
        throw std::invalid_argument("Denominator cannot be 0. 4r3 Y0U Cr4zY?");

    int cd = std::gcd(num, denom);
    return Fraction(num / cd, denom / cd);
}

Fraction Fraction::operator+(const Fraction &f_1) const {
    int num = this->numerator_ * f_1.denominator_ + this->denominator_ * f_1.numerator_;
    int denom = this->denominator_ * f_1.denominator_;

    if (denom == invalidDenominatorValue)
        throw std::invalid_argument("Denominator cannot be 0. 4r3 Y0U Cr4zY?");

    int cd = std::gcd(num, denom);
    return Fraction(num / cd, denom / cd);
}

Fraction::Fraction(int numerator, int denominator): numerator_(numerator), denominator_(denominator){
    if (denominator == invalidDenominatorValue)
        throw std::invalid_argument("Denominator cannot be 0. 4r3 Y0U Cr4zY?");
}

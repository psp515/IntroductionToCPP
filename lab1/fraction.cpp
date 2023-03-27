#include <iostream>
#include <sstream>

using namespace std;

#include "fraction.h"

#ifdef UNIMPLEMENTED_classFraction
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif



void Fraction::setNumerator(int numerator) {
    numerator_ = numerator;
}

int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}

int Fraction::getDefaultDenominatorValue() {
    return defaultDenominatorValue;
}

void Fraction::print() const {
    cout << numerator_ << "/" << denominator_ << endl;
}

string Fraction::getFractionName() const {
    return fractionName_;
}

int Fraction::removedFractions_ = 0;

int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    return denominator_;
}

void Fraction::setDenominator(int denominator) {
    denominator_ = denominator;
}

int Fraction::removedFractions() {
    return removedFractions_;
}



void Fraction::save(ostream &os) const {
    os << numerator_ << '/' << denominator_;
}

void Fraction::load(istream &is) {
    std::string token;

    getline(is, token, '/');
    numerator_ = std::stoi(token);
    getline(is, token);
    denominator_ = std::stoi(token);
}

void Fraction::add(const Fraction& x) {
    denominator_ = denominator_ * x.denominator_;
    numerator_ = numerator_ * x.denominator_ + x.numerator_ * denominator_;
}

void Fraction::reduce() {
    int _gdc = gcd(numerator_, denominator_);

    numerator_ = int(numerator_ / _gdc);
    denominator_ = int(denominator_/_gdc);
}

void Fraction::multiply(const Fraction& x)
{
    numerator_ = numerator_ * x.numerator_;
    denominator_ = denominator_ * x.denominator_;
}

void Fraction::divide(const Fraction& x)
{
    numerator_ = numerator_ * x.denominator_;
    denominator_ = denominator_ * x.numerator_;
}

int Fraction::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

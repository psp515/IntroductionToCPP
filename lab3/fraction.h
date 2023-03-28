#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:

    explicit Fraction(int numerator = 0, int denominator = defaultDenominatorValue);

    Fraction operator*(const Fraction& f_1) const;
    Fraction operator+(const Fraction& f_1) const;

    int numerator() const;
    void setNumerator(int numerator);

    int denominator() const;
    void setDenominator(int numerator);


private:
    int numerator_;
    int denominator_;

    constexpr static int invalidDenominatorValue = 0;
    constexpr static int defaultDenominatorValue = 1;
};


#endif // FRACTION_H

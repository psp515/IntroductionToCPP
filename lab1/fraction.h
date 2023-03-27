#ifndef TASK1_FRACTION_H
#define TASK1_FRACTION_H

#include <iosfwd>
#include <string>
#include <utility>
#endif // TASK1_FRACTION_H

class Fraction
        {
public:
    explicit Fraction(int numerator_, int denominator_ = defaultDenominatorValue, std::string fractionName = "")
    {
        this->denominator_ = denominator_;
        this->numerator_ = numerator_;
        this->fractionName_ = std::move(fractionName);
    }
    Fraction()
    {
        this->denominator_ = 0;
        this->numerator_ = 1;
    }

    ~Fraction(){
        removedFractions_ += 1;
    }

    int getNumerator() const;
    void setNumerator(int numerator);

    int getDenominator() const;
    void setDenominator(int numerator);

    void print() const;

    std::string getFractionName() const;

    void save(std::ostream& os) const;
    void load(std::istream& is);

    void add(const Fraction& x);
    void multiply(const Fraction& x);
    void divide(const Fraction& x);
    void reduce();

    static int removedFractions();

    static int getDefaultDenominatorValue();
    static int getInvalidDenominatorValue();

protected:
            int numerator_;
            int denominator_;
            std::string fractionName_;
private:
            int gcd(int a, int b);
            static int removedFractions_;
            constexpr static int invalidDenominatorValue = 0;
            constexpr static int defaultDenominatorValue = 1;
        };
#pragma once
#include <iostream>
namespace ariel{

class Fraction{
    private:
        int _numerator;
        int _denominator;

        Fraction& reduce();
        static int lcm(int val1, int val2);
        static int gcd(int val1, int val2);

    public:

        Fraction(int numer=0, int denom=1);
        Fraction(double val);
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(Fraction const &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        Fraction operator+(const float &other) const;
        Fraction operator-(const float &other) const;
        Fraction operator-(const int &other) const;
        Fraction operator*(const float &other) const;
        Fraction operator/(const float &other) const;
        bool operator==(const Fraction &other) const;
        bool operator==(const float &other) const;
        bool operator<(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;

        bool operator<(const float &other) const;
        bool operator<=(const float &other) const;
        bool operator>(const float &other) const;
        bool operator>=(const float &other) const;
        //prefix inc
        Fraction& operator++();
        //postfix inc
        Fraction operator++(int dummy_flag);
        //prefix dec
        Fraction& operator--();
        //postfix dec
        Fraction operator--(int dummy_flag);

        friend std::ostream& operator<<(std::ostream& output, const Fraction& fra);
        friend std::istream& operator>>(std::istream& input , Fraction& fra);

        friend Fraction operator-(const Fraction& fr1, const float& fr2);
        friend Fraction operator*(const Fraction& fr1, const float& fr2);
        friend Fraction operator*(float const &fr1, Fraction const &fr2);
        friend Fraction operator-(const float& fr1, const Fraction& fr2);
        friend Fraction operator*(const float& fr1, const Fraction& fr2);
};

}
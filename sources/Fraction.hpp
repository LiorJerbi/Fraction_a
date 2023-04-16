#pragma once
#include <iostream>
namespace ariel{

class Fraction{
    private:
        int _numerator;
        int _denominator;  

    public:

        Fraction(int numer, int denom);
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        Fraction operator+(const float &other) const;
        Fraction operator-(const float &other) const;
        Fraction operator*(const float &other) const;
        Fraction operator/(const float &other) const;
        bool operator==(const Fraction &other) const;

        int operator<(const Fraction &other) const;
        int operator<=(const Fraction &other) const;
        int operator>(const Fraction &other) const;
        int operator>=(const Fraction &other) const;

        int operator<(const float &other) const;
        int operator<=(const float &other) const;
        int operator>(const float &other) const;
        int operator>=(const float &other) const;
        //prefix inc
        Fraction& operator++();
        //postfix inc
        Fraction operator++(int dummy_flag);
        //prefix dec
        Fraction& operator--();
        //postfix dec
        Fraction operator--(int dummy_flag);

        friend std::ostream& operator<< (std::ostream& output, const Fraction& f);
        friend std::istream& operator>> (std::istream& input , Fraction& f);
        friend std::ostream& operator<< (const Fraction& f,std::ostream& input);
        friend std::istream& operator>> (Fraction& f,std::istream& output);

        friend Fraction operator- (const Fraction& f1, const float& f2);
        friend Fraction operator* (const Fraction& f1, const float& f2);
        friend Fraction operator- (const float& f1, const Fraction& f2);
        friend Fraction operator* (const float& f1, const Fraction& f2);
};

}
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
        // Fraction operator-(const Fraction &other) const;
        Fraction operator-(Fraction const &other) const{return *this;}
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        Fraction operator+(const float &other) const;
        Fraction operator-(const float &other) const;
        Fraction operator-(const int &other) const;
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

        friend std::ostream& operator<<(std::ostream& output, Fraction const& fra){return output;}
        friend std::ostream& operator<<(std::ostream& output, const Fraction& fra);
        friend std::istream& operator>>(std::istream& input , Fraction& fra);
        friend std::ostream& operator<<(const Fraction& fra,std::ostream& input);
        friend std::istream& operator>>(Fraction& fra,std::istream& output);

        friend Fraction operator-(const Fraction& fr1, const float& fr2);
        friend Fraction operator*(const Fraction& fr1, const float& fr2);
        friend Fraction operator*(float const &fr1, Fraction const &fr2){return fr2;}
        friend Fraction operator-(const float& fr1, const Fraction& fr2);
        friend Fraction operator*(const float& fr1, const Fraction& fr2);
};

}
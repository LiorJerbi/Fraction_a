#include <cmath>
#include "Fraction.hpp"
using namespace ariel;

    Fraction::Fraction(int numer, int denom){
        if(denom== 0){
            if(numer == 0){
                _numerator=numer;
                _denominator=denom;
            }
            else{
                throw std::runtime_error("Cannot divide in zero!");
            }
        }
        else{
            if(numer<0&&denom<0 || numer>0 && denom<0){       // -a / -b || a / -b
                _numerator=-numer;
                _denominator=-denom;
            }
            else{                                           // -a / b || a / b
                _numerator=numer;
                _denominator=denom; 
            }
        }      
    }
    Fraction::Fraction(double val){
    int mult = pow(10, 3);        // 3 digits after the dot
    int numer = static_cast<int>(round(val * mult));
    int denom = mult;

    int gcdv = gcd(numer, denom);
    _numerator = numer / gcdv;
    _denominator = denom / gcdv;
    }

    int Fraction::gcd(int val1, int val2){
        if(val2==0){
            return abs(val1);
        }
        return gcd(val2, val1%val2);
    }
    int Fraction::lcm(int val1, int val2){
        int gcdval = gcd(val1,val2);
        return (val1 / gcdval) * val2;
    }

    Fraction& Fraction::reduce(){
        int gcdval = gcd(_numerator,_denominator);
        _numerator /= gcdval;
        _denominator /= gcdval;
        return *this;
    }


    Fraction Fraction::operator+(const Fraction &other) const{
        int ndenom = lcm(_denominator,other._denominator);
        int nnume = _numerator * (ndenom / _denominator) + other._numerator * (ndenom / other._denominator);
        return Fraction(nnume, ndenom).reduce();
    }
    Fraction Fraction::operator-(Fraction const &other) const{
        int ndenom = lcm(_denominator,other._denominator);
        int nnume = _numerator * (ndenom / _denominator) - other._numerator * (ndenom / other._denominator);
        return Fraction(nnume, ndenom).reduce();       
    }
    Fraction Fraction::operator*(const Fraction &other) const{
        return Fraction(_numerator * other._numerator, _denominator * other._denominator).reduce();
    }
    Fraction Fraction::operator/(const Fraction &other) const{
        if(other._numerator==0){
            throw std::invalid_argument("Division in zero!");
        }
        return Fraction(_numerator * other._denominator, _denominator * other._numerator).reduce();
    }

    Fraction Fraction::operator+(const float &other) const{
        float roundv = roundf(other * 1000.0f) / 1000.0f;           // to have 3 digits after the dot
        int nnume= static_cast<int>(roundv * 1000);
        int ndenom = 1000;
        int lcmv = lcm(_denominator,ndenom);
        int nnume1 = _numerator * (lcmv / _denominator);
        int nnume2 = nnume * (lcmv / ndenom);
        return Fraction(nnume1 + nnume2,lcmv).reduce();
    }
    Fraction Fraction::operator-(const float &other) const{
        float roundv = roundf(other * 1000.0f) / 1000.0f;           // to have 3 digits after the dot
        int nnume= static_cast<int>(roundv * 1000);
        int ndenom = 1000;
        int lcmv = lcm(_denominator,ndenom);
        int nnume1 = _numerator * (lcmv / _denominator);
        int nnume2 = nnume * (lcmv / ndenom);
        return Fraction(nnume1 - nnume2,lcmv).reduce();
    }
    Fraction Fraction::operator-(const int &other) const{
        Fraction temp(other,1);
        return (*this) - temp;
    }
    Fraction Fraction::operator*(const float &other) const{
        float roundv = roundf(other * 1000.0f) / 1000.0f;           // to have 3 digits after the dot
        float frac = static_cast<double>(_numerator) * roundv / _denominator;
        return Fraction(frac).reduce();
    }
    Fraction Fraction::operator/(const float &other) const{
        if(other == 0){
            throw std::invalid_argument("Division in zero!");
        }
        float roundv = roundf(other * 1000.0f) / 1000.0f;           // to have 3 digits after the dot
        float q = static_cast<double>(_numerator) / (roundv * _denominator);
        return Fraction(q).reduce();
    }

    bool Fraction::operator==(const Fraction &other) const{
        Fraction tfrac = *this;
        Fraction ofrac = other;
        tfrac.reduce();
        ofrac.reduce();
        return tfrac._numerator == ofrac._numerator && tfrac._denominator == ofrac._denominator;
    }
    bool Fraction::operator<(const Fraction &other) const{
        int lcmv = lcm(_denominator,other._denominator);
        int this_numer = _numerator * (lcmv / _denominator);
        int other_numer = other._numerator * (lcmv / other._denominator);
        return this_numer < other_numer;
    }
    bool Fraction::operator>(const Fraction &other) const{
        int lcmv = lcm(_denominator,other._denominator);
        int this_numer = _numerator * (lcmv / _denominator);
        int other_numer = other._numerator * (lcmv / other._denominator);
        return this_numer > other_numer;
    }
    bool Fraction::operator>=(const Fraction &other) const{
        return (*this > other) || (*this == other);
    }
    bool Fraction::operator<=(const Fraction &other) const{
        return (*this < other) || (*this == other);
    }    

    bool Fraction::operator==(const float &other) const{
        return *this == Fraction(other);
    }
    bool Fraction::operator<(const float &other) const{
        return *this < Fraction(other);
    }
    bool Fraction::operator>(const float &other) const{
        return *this > Fraction(other);
    }
    bool Fraction::operator<=(const float &other) const{
        return (*this < other) || (*this == other);
    }
    bool Fraction::operator>=(const float &other) const{
        return (*this > other) || (*this ==other);
    }
    //prefix inc
    Fraction& Fraction::operator++(){
        _numerator+=_denominator;
        return *this;
    }
    //postfix inc
    Fraction Fraction::operator++(int dummy_flag){
        Fraction copy=*this;
        _numerator+=_denominator;
        return copy;
    }
    //prefix dec
    Fraction& Fraction::operator--(){
        _numerator-=_denominator;
        return *this;
    }
    //postfix dec
    Fraction Fraction::operator--(int dummy_flag){
        Fraction copy=*this;
        _numerator-=_denominator;
        return copy;
    }

    std::ostream& ariel::operator<<(std::ostream& output, const Fraction& fra){
        output << fra._numerator << "/" << fra._denominator << " ";
        return output;
    }
    std::istream& ariel::operator>>(std::istream& input , Fraction& fra){
        int numerator, denominator;
        char separator;
        input >> numerator >> separator >> denominator;
        if (separator != '/') {
            input.setstate(std::ios_base::failbit);
            return input;
        }
        fra = Fraction(numerator, denominator);
        return input;
    }

    Fraction ariel::operator-(const Fraction& f1, const float& f2){
        Fraction tf2(f2);
        return f1-tf2;
    }
    Fraction ariel::operator*(const Fraction& f1, const float& f2){
        Fraction tf2(f2);
        return f1*tf2;
    }
    Fraction ariel::operator-(const float& f1, const Fraction& f2){
        Fraction tf1(f1);
        return tf1-f2;    
    }
    Fraction ariel::operator*(const float& f1, const Fraction& f2){
        Fraction tf1(f1);
        return tf1*f2; 
    }
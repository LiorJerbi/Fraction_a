
#include "Fraction.hpp"
using namespace ariel;

    Fraction::Fraction(int numer, int denom):_numerator(numer),_denominator(denom){
    }
    Fraction Fraction::operator+(const Fraction &other) const{return *this;}
    Fraction Fraction::operator*(const Fraction &other) const{return *this;}
    Fraction Fraction::operator/(const Fraction &other) const{return *this;}
    Fraction Fraction::operator+(const float &other) const{return *this;}
    Fraction Fraction::operator-(const float &other) const{return *this;}
    Fraction Fraction::operator*(const float &other) const{return *this;}
    Fraction Fraction::operator/(const float &other) const{return *this;}
    bool Fraction::operator==(const Fraction &other) const{return false;}

    int Fraction::operator<(const Fraction &other) const{return 0;}
    int Fraction::operator<=(const Fraction &other) const{return 0;}
    int Fraction::operator>(const Fraction &other) const{return 0;}
    int Fraction::operator>=(const Fraction &other) const{return 0;}

    int Fraction::operator<(const float &other) const{return 0;}
    int Fraction::operator<=(const float &other) const{return 0;}
    int Fraction::operator>(const float &other) const{return 0;}
    int Fraction::operator>=(const float &other) const{return 0;}
    //prefix inc
    Fraction& Fraction::operator++(){return *this;}
    //postfix inc
    Fraction Fraction::operator++(int dummy_flag){Fraction copy=*this; return copy;}
    //prefix dec
    Fraction& Fraction::operator--(){return *this;}
    //postfix dec
    Fraction Fraction::operator--(int dummy_flag){Fraction copy=*this; return copy;}

    std::ostream& operator<< (std::ostream& output, const Fraction& f){return output;}
    std::istream& operator>> (std::istream& input , Fraction& f){return input;}
    std::ostream& operator<< (const Fraction& f,std::ostream& input){return input;}
    std::istream& operator>> (Fraction& f,std::istream& output){return output;}

    Fraction operator- (const Fraction& f1, const float& f2){return f1;}
    Fraction operator* (const Fraction& f1, const float& f2){return f1;}
    Fraction operator- (const float& f1, const Fraction& f2){return f2;}
    Fraction operator* (const float& f1, const Fraction& f2){return f2;}

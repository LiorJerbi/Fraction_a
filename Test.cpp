#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdexcept>
using namespace ariel;
using namespace std;

TEST_CASE("Comprasion Cases:"){
    Fraction a(2,4);
    Fraction b(1,2);
    Fraction c(3,2);
    Fraction d(0,1);
    Fraction e(-1,2);

    CHECK(a==b);
    CHECK(a<c);
    CHECK(b>d);
    CHECK(d>=0);
    CHECK(e<=d);
}

TEST_CASE("Throwing exceptions from operators:"){
    Fraction a(7,2);
    Fraction b(12,5);
    CHECK_NOTHROW(a+b);
    CHECK_NOTHROW(a*b);
    CHECK_NOTHROW(a-b);
    CHECK_NOTHROW(a/b);
    CHECK_NOTHROW(a++);
    CHECK_NOTHROW(--b);

    b=b-b;
    CHECK_THROWS(a/b);  //divide in zero;

}
TEST_CASE("Arithmetic Cases:"){
    Fraction a(5,2);
    Fraction b(1,2);
    CHECK(b==b+2.0);
    CHECK(a-2.0==b);
    b=b-b;
    CHECK(a*0.0==b);
    Fraction c(1,2);
    CHECK(++c==--a);

}

TEST_CASE("Fraction reduction tests:"){
    Fraction a(5,2);
    Fraction b(1,2);
    CHECK(a-b<=2.0);
    CHECK(a+b>=3.0);
    CHECK((a*0.2)==b);
    Fraction a(1,4);
    CHECK(a==(0.5*b));
}

TEST_CASE("Ostream Tests:"){
    Fraction a(7,4);
    CHECK_NOTHROW(cout << a << endl); 
    CHECK_NOTHROW(cout << 1.72*a << endl);
    Fraction b(16,9);
    CHECK_NOTHROW(cout << (b<=a) << endl);
}
#include "fraction.h"
#include <iostream>

//constructor
Fraction::Fraction(){numerator = 0; denominator = 1;}
Fraction::Fraction(float n, float d): numerator(n), denominator(d) {}

//overload methods
Fraction Fraction::operator+=(const Fraction& f)
{
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
    return *this;
}

Fraction Fraction::operator-=(const Fraction& f)
{
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;
    return *this;
}

Fraction Fraction::operator*=(const Fraction& f)
{
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;
    return *this;
}


Fraction Fraction::operator/=(const Fraction& f)
{
    numerator = numerator * f.denominator;
    denominator = denominator * f.numerator;
    return *this;
}


Fraction Fraction::operator+(const Fraction& f)
{
    Fraction temp = *this;
    temp += f;
    return temp;
}

Fraction Fraction::operator-(const Fraction& f)
{
    Fraction temp;
    temp.numerator = numerator * f.denominator - f.numerator * denominator;
    temp.denominator = denominator * f.denominator;
    return temp;
}

Fraction Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator++()
{
    numerator = numerator + denominator;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    in >> f.numerator >> f.denominator;
    return in;
}



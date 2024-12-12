// Declaration of a class Fraction with a numerator and demominator of type long
#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H
class Fraction
{
    private:
    float numerator;
    float denominator;


    public:
    Fraction();
    Fraction(float, float);

    int getNumerator() const {return numerator;}
    int getDenominator() const {return denominator;}

    //overload += -= *= /=
    Fraction operator+=(const Fraction&);
    Fraction operator-=(const Fraction&);
    Fraction operator*=(const Fraction&);
    Fraction operator/=(const Fraction&);


    //overloaded operators
    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);

    //overload -- and ++
    Fraction operator--();
    Fraction operator++();


    //overload << and >>1
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);

};

#endif
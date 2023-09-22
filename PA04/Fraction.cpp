#include <iostream>
#include <vector>
#include <Fraction.h>


using namespace std;

Fraction::Fraction(int top, int bottom) {
    num = top;
    den = bottom;
}

int Fraction::getNum() const {
    return num;
}

int Fraction::getDen() const {
    return den;
}

//overload the << operator to output a Fraction object
ostream& operator<<(ostream& stream, const Fraction& frac) {
    stream << frac.num << "/" << frac.den;
    return stream;
}

//overload the + operator
Fraction Fraction::operator+(const Fraction & other) const{
    int othernum = other.getNum();
    int otherden = other.getDen();
    int placeholdernum = num;
    int placeholderden = den;
    placeholdernum = placeholdernum * otherden;
    othernum = othernum*placeholderden;
    placeholderden *= otherden;
    Fraction sum(placeholdernum + othernum, placeholderden);
    return sum;
}

Fraction Fraction::operator-(const Fraction & other) const {
    int othernum = other.getNum();
    int otherden = other.getDen();
    int placeholdernum = num;
    int placeholderden = den;
    placeholdernum = placeholdernum * otherden;
    othernum = othernum*placeholderden;
    placeholderden *= otherden;
    Fraction diff(placeholdernum - othernum, placeholderden);
    return diff;
}

Fraction Fraction::operator*(const Fraction & other) const {
    int othernum = other.getNum();
    int otherden = other.getDen();
    int placeholdernum = num;
    int placeholderden = den;
    placeholdernum *= othernum;
    placeholderden *= otherden;
    Fraction product(placeholdernum, placeholderden);
    return product;
}

Fraction Fraction::operator/(const Fraction & other) const {
    int othernum = other.getNum();
    int otherden = other.getDen();
    int placeholdernum = num;
    int placeholderden = den;
    placeholdernum *= otherden;
    placeholderden *= othernum;
    Fraction product(placeholdernum, placeholderden);
    return product;
}

bool Fraction::operator ==(Fraction &other) const {
    int othernumint = other.getNum();
    int otherdenint = other.getDen();
    double othernum = static_cast<double>(othernumint);
    double otherden = static_cast<double>(otherdenint);
    double placeholdernum = static_cast<double>(num);
    double placeholderden = static_cast<double>(den);
    double rationum = placeholdernum/othernum;
    double ratioden = placeholderden/otherden;
    if (rationum == ratioden) {
        return true;
    }
    return false;
}

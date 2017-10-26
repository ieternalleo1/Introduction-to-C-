/** Implementation of Complex Class*/
#include "Complex.h"
#include <cmath>
#include <iostream>

using namespace std;

//Implement constructors
Complex::Complex(){}
Complex::Complex(double real)
{
    this->real = real;
}
Complex::Complex(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
}

Complex Complex::add(const Complex secondComplex) const{
    Complex sum;
    sum.real = real + secondComplex.real;
    sum.imaginary = imaginary + secondComplex.imaginary;

    return sum;
}
Complex Complex::subtract(const Complex secondComplex) const{
    Complex difference;
    difference.real = real - secondComplex.real;
    difference.imaginary = imaginary - secondComplex.imaginary;

    return difference;
}

Complex Complex::multiply(const Complex secondComplex) const
{
    Complex product;
    double c = secondComplex.real;
    double d = secondComplex.imaginary;
    product.real = (real * c) - (imaginary * d);
    product.imaginary = (imaginary * c) + (real * d);

    return product;
}
Complex Complex::divide(const Complex secondComplex) const
{
    Complex quotient;
    double c = secondComplex.getRealPart();
    double d = secondComplex.getImaginaryPart();
    quotient::real = (real * c + imaginary*d)/(pow(c,2) + pow(d,2));
    quotient::imaginary = (imaginary * c - real * d)/(pow(c,2) + pow(d,2));

    return quotient;
}
double Complex::abs() const
{
    return sqrt(pow(real,2) + pow(imaginary,2));
}
string Complex::toString() const
{
    string complex_string = "";
    string s_real = to_string(real);
    string s_imaginary = to_string(imaginary);
     
    complex_string = (s_imaginary == "0" ?  s_real: s_real + " + " + s_imaginary + "i");
    return complex_string;
}

double Complex::getRealPart() const
{
    return real;
}

double Complex::getImaginaryPart() const
{
    return imaginary;
}

int Complex::compareTo(const Complex secondComplex) const
{
    double c1_abs = this->abs();
    double c2_abs = secondComplex.abs();
    if(c1_abs == c2_abs)
    {
        return 0;
    }
    else if(c1_abs > c2_abs)
    {
        return 1;
    }
    else
    return -1;
}


/** Implement function operators for augment operators */
Complex& Complex::operator+=(const Complex& secondComplex)
{
    *this = add(secondComplex);
    return *this;
}
Complex& Complex::operator-=(const Complex& secondComplex)
{
    *this = subtract(secondComplex);
    return *this;
}
Complex& Complex::operator/=(const Complex& secondComplex)
{
    *this = divide(secondComplex);
    return *this;
}
Complex& Complex::operator*=(const Complex& secondComplex)
{
    *this = multiply(secondComplex);
    return *this;
}

/**Define function operator for []*/
double& Complex::operator[](int index)
{
    try{

        return (index == 1 ? imaginary: real);
    }
    catch(exception &ex)
    {
        cout << "Error: Cannot not acces value at index: " << index;
    }
}

/**Define function operators for postfix ++ and -- */
Complex& Complex::operator++(int dummy) //postfix
{
    Complex c(1);
    Complex temp = *this;
     *this = add(c);
    return temp;
}
Complex& Complex::operator--(int dummy) //postfix --
{
    Complex c(1);
    Complex temp = *this;
    *this  = subtract(c);
    return temp;
}
/**Define function operators for prefix ++ and --*/
Complex& Complex::operator++() //prefix
{
    Complex c(1);
    *this = add(c);
    return *this;
}  

Complex& Complex::operator--() //prefix --
{
    Complex c(1);
    *this = subtract(c);
    return *this;
}



/** Define the << and >> operators */
friend ostream& Complex::operator<<(ostream& out, const Complex& complex)
{
    out << complex.toString();
    return out;
}
friend istream& Complex::operator>>(istream& in, const Complex& complex)
{
    cout << "Enter real number: "
    in >> complex.getRealPart();
    cout << "Enter Imaginary Numbers: "
    in >> complex.getImaginaryPart();

    return in;
}


/**Non Member Functions */

//Define nonmember function operators for relational operators
bool operator<(const Complex& c1, const Complex& c2)
{
   return c1.compareTo(c2) != -1 ? false:true;
}
bool operator<=(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) == 1 ? false:true;
}
bool operator==(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) != 0 ? false:true;
}
bool operator!=(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) == 0 ? false:true;
}
bool operator>(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) < 1 ? false: true;
}
bool operator>=(const Complex& c1, const Complex& c2)
{
        return c1.compareTo(c2) < 0 ? false:true;
}

//Define nonmember function operators for arithmetic operators
Complex operator+(const Complex& c1, const Complex& c2)
{
    return c1.add(c2);
}
Complex operator-(const Complex& c1, const Complex& c2)
{
    return c1.subtract(c2);
}
Complex operator*(const Complex& c1, const Complex& c2)
{
    return c1.multiply(c2);
}
Complex operator/(const Complex& c1, const Complex& c2)
{
    return c1.divide(c2);
}
/** Implementation of Complex Class*/
#include "Complex.h"
#include <cmath>

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
    double c = secondComplex.real;
    double d = secondComplex.imaginary;
    quotient.real = (real * c + imaginary*d)/(pow(c,2) + pow(d,2));
    quotient.imaginary = (imaginary * c - real * d)/(pow(c,2) + pow(d,2));

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
Complex& Complex::operator++(int dummy); //postfix
Complex& Complex::operator--(int dummy); //postfix --

/**Define function operators for prefix ++ and --*/
Complex& Complex::operator++(); //prefix    
Complex& Complex::operator--(); //prefix --

/** Define Function operators for unary + and - */
Complex Complex::operator-();
Complex Complex::operator+();

/** Define the << and >> operators */
friend ostream& Complex::operator<<(ostream& out, const Complex& complex);
friend istream& Complex::operator>>(istream& in, const Complex& complex);


/**Non Member Functions */

//Define nonmember function operators for relational operators
bool operator<(const Complex& c1, const Complex& c2);
bool operator<=(const Complex& c1, const Complex& c2);
bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);
bool operator>(const Complex& c1, const Complex& c2);
bool operator>=(const Complex& c1, const Complex& c2);

//Define nonmember function operators for arithmetic operators
Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);
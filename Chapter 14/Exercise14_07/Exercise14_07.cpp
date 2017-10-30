//
// Created by leo on 10/25/17.
//
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;
class Complex
{
    /**Member Functions */
public:
    /**Creates a  Complex object for number 0*/
    Complex();
    Complex(double real); //suitable for type conversion
    Complex(double real, double imaginary);
    
    Complex add(const Complex secondComplex) const;
    Complex subtract(const Complex secondComplex) const;
    Complex divide(const Complex secondComplex) const;
    Complex multiply(const Complex secondComplex) const;
    double abs() const;
    string toString() const;
    double getRealPart() const;
    double getImaginaryPart() const;
    int compareTo(const Complex secondComplex) const;
    
    
    /**Define function operators for augmented operators*/
    Complex& operator+=(const Complex& secondComplex);
    Complex& operator-=(const Complex& secondComplex);
    Complex& operator/=(const Complex& secondComplex);
    Complex& operator*=(const Complex& secondComplex);
    
    /**Define function operator for []*/
    double& operator[](int index);
    
    /**Define function operators for postfix ++ and -- */
    Complex operator++(int dummy); //postfix
    Complex operator--(int dummy); //postfix --
    
    /**Define function operators for prefix ++ and --*/
    Complex& operator++(); //prefix
    Complex& operator--(); //prefix --
    
    /** Define Function operators for unary + and - */
    Complex operator-();
    Complex operator+();
    
    /** Define the << and >> operators */
    friend ostream& operator<<(ostream& out, const Complex& complex);
    friend istream& operator>>(istream& in,  Complex& complex);
    
    
    /**Data Fields*/
private:
    double real = 0;
    double imaginary = 0;
};


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
    
    stringstream stream;
    stream << fixed << setprecision(2) <<real << imaginary;
    string s_real(stream.str());
    string s_imaginary(stream.str());
    string complex_string = (s_imaginary == "0" ?  s_real: s_real + " + " + s_imaginary + "i");
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
    //try{
        
        return (index == 1 ? imaginary: real);
    //}
//    catch(exception ex)
//    {
//        cout << "Error: Cannot not acces value at index: " << index;
//    }
}

/**Define function operators for postfix ++ and -- */
Complex Complex::operator++(int dummy) //postfix
{
    Complex temp(real,imaginary);
    this->add(1);
    return temp;
}

Complex Complex::operator--(int dummy) //postfix --
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
ostream& operator<<(ostream& out, const Complex& complex)
{
    out << complex.toString();
    return out;
}


istream& operator>>(istream& in,  Complex& complex)
{
    cout << "Enter real number: ";
    in >> complex.real;
    cout << "Enter Imaginary Numbers: ";
    in >> complex.imaginary;
    
    return in;
}


/**Non Member Functions */

//Define nonmember function operators for relational operators
bool operator<(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) < 0;
}
bool operator<=(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) < 1;
}
bool operator==(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) == 0;
}
bool operator!=(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) != 0;
}
bool operator>(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) > 0;
}
bool operator>=(const Complex& c1, const Complex& c2)
{
    return c1.compareTo(c2) > -1;
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

int main()
{
    Complex number1;
    cout << "Enter the first complex number: ";
    cin >> number1;
    
    Complex number2;
    cout << "Enter the second complex number: ";
    cin >> number2;
    
    cout << "(" << number1 << ")" << " + " << "(" << number2
         << ") = " << (number1 + number2) << endl;
    cout << "(" << number1 << ")" << " - " << "(" << number2
         << ") = " << (number1 - number2) << endl;
    cout << "(" << number1 << ")" << " * " << "(" << number2
         << ") = " << (number1 * number2) << endl;
    cout << "(" << number1 << ")" << " / " << "(" << number2
         << ") = " << (number1 / number2) << endl;
    cout << "|" << number1 << "|" << " = " << number1.abs() << endl;
    
    number1[0] = 3.4;
    cout << number1++ << endl;
    cout << ++number2 << endl;
    cout << (3 + number2) << endl;
    cout << (number2 += number1) << endl;
    cout << (number2 *= number1) << endl;
    
    return 0;
}

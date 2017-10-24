/** Design a class named Complex for representing complex numbers 
 * and the functions add, subtract, multiply, divide, abs for performing complex-number operations, 
 * and the toString function for returning a string representation for a complex number. 
 * The toString function returns a + bi as a string. If b is 0, it simply returns a.
 * Provide three constructors Complex(a, b), Complex(a), and Complex(). 
 *          Complex() creates a Complex object for number 0
 *          Complex(a) creates a Complex object with 0 for b. 
 * Provide the getRealPart() and getImaginaryPart() functions for returning the real and imaginary part of the complex number, respectively.
 * Overload the operators +, -, *, /, +=, -=, *=, /=, [], unary + and -, prefix ++ and --, postfix ++ and --, <<, >>.
 * Overload [] so that [0] returns a and [1] returns b.
 * Overload the relational operators <, <=, ==, !=, >, >= by comparing the absolute values of two complex numbers.
 * Overload the operators +, -, *, /, <<, >>. <, <=, ==, !=, >, >= as nonmember functions. */

 #ifndef COMPLEX_H
 #define COMPLEX_H
 #include <string>

 using namespace std;
 class Complex
 {
 public:
    Complex();
    Complex(int real);
    Complex(int real, int imaginary);
    Complex operator+(const Complex secondComplex) const;
    Complex operator-(const Complex secondComplex) const;
    Complex operator/(const Complex secondComplex) const;
    Complex operator*(const Complex secondComplex) const;
    Complex& operator+=(const Complex& seconsComplex);




 };
 #endif
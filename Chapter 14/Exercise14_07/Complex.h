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
    Complex& operator++(int dummy); //postfix
    Complex& operator--(int dummy); //postfix --
   
    /**Define function operators for prefix ++ and --*/
    Complex& operator++(); //prefix    
    Complex& operator--(); //prefix --
    
    /** Define Function operators for unary + and - */
    Complex operator-();
    Complex operator+();
    
    /** Define the << and >> operators */
    friend ostream& operator<<(ostream& out, const Complex& complex);
    friend istream& operator>>(istream& in, const Complex& complex);
    

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
 
 
 
 #endif
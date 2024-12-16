#include <iostream> 
using namespace std; 
 
class complex { 
private: 
    int real; 
    int imag; 
 
public: 
    // Default constructor 
    complex() {}; 
 
    // Member functions 
    void setvalue(int, int); 
    void display(); 
     
    // Operator overloading 
    complex operator* (complex &b); 
    complex operator+ (complex &d); 
 
    // Friend functions 
    friend void operator <<(ostream &output, complex &s); 
    friend void operator >>(istream &input, complex &q); 
}; 
 
// Member function definitions 
void complex::setvalue(int c, int d) { 
    real = c; 
    imag = d; 
} 
 
void complex::display() { 
    cout << real << "+" << imag << "i" << "\n"; 
} 
 
// Friend function definitions 
void operator<<(ostream &output, complex &s) { 
    output << s.real << "+" << s.imag << "i"; 
} 
 
void operator>>(istream &input, complex &q) { 
    input >> q.real >> q.imag; 
} 
 
// Operator overloading definitions 
complex complex::operator*(complex &b) { 
    complex c7; 
    c7.real = real * b.real; 
    c7.imag = imag * b.imag; 
    return c7; 
} 
 
complex complex::operator+(complex &d) { 
    complex c8; 
    c8.real = real + d.real; 
    c8.imag = imag + d.imag; 
    return c8; 
} 
 
// Main function 
int main() { 
    complex c1, c2, c3, c4; 
 
    // Input first complex number 
    cout << "Enter first No: " << "\n"; 
    cin >> c3; 
    cout << "Object first is:\n" << c3; 
 
    // Input second complex number 
    cout << "\nEnter Second No: "; 
    cin >> c4; 
    cout << "Object second is:" << c4; 
 
    // Perform addition and multiplication 
    c1 = c3 + c4; 
    c2 = c3 * c4; 
 
    // Output results 
    cout << "\n Results are: \n Addition is: " << c1; 
    cout << "\n Multiplication is: " << c2; 
 
    return 0; 
} 

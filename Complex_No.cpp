#include <iostream>


class Complex_Number{
public:
    float real_no, imag_no;

    Complex_Number(){}

    Complex_Number(float input) : real_no(input), imag_no(input) {}

    Complex_Number(float real, float imag) : real_no(real), imag_no(imag) {}


    Complex_Number& operator+(Complex_Number const& other){
        Complex_Number res(this->real_no + other.real_no, this->imag_no + other.imag_no);
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex_Number& no);
};


std::ostream& operator<<(std::ostream& os, const Complex_Number& no){
    os << no.real_no << " + i" << no.imag_no;
    return os;
}



int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122" << std::endl;


    Complex_Number a(2), b(1, 2);

    auto c = a+b;

    std::cout << "\nSum of complex NOs '" << a << "' and '" << b << "' is :\n" << c << std::endl;

}
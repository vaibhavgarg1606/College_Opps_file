#include <iostream>


template <class dataType>
dataType Sqaure(dataType value){
    return value * value;
}



int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n" << std::endl;

    int a;
    float b;

    std::cout << "Enter an integer to find its square: ";
    std::cin >> a;
    std::cout << "sqaure of " << a << " is : " << Sqaure(a) << std::endl; 

    std::cout << "\nEnter a float to find its square: ";
    std::cin >> b;
    std::cout << "sqaure of " << b << "is : " << Sqaure(b) << std::endl; 



}
#include <iostream>


class Class2;

class Class1{
private:
    float Num1;
    
public:
    Class1(float value) : Num1 (value) {}

    friend float greatest_no(const Class1 a, const Class2 b);
};



class Class2{
private:
    float Num2;
    
public:
    Class2(float value) : Num2 (value) {}

    friend float greatest_no(const Class1 a, const Class2 b);
};



float greatest_no(const Class1 a, const Class2 b){
    return a.Num1 > b.Num2 ? a.Num1 : b.Num2;
}


int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122" << std::endl;

    Class1 class1(12.5f);
    Class2 class2(7.65f);

    std::cout << "\nThe Greatest no is: " << greatest_no(class1, class2) << std::endl;

}


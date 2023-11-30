#include <iostream>


template <class dataType>
class BiggerNumber{
private:
    dataType num1, num2;

public:

    BiggerNumber(dataType num1, dataType num2) : num1(num1), num2(num2){
        std::cout << "\nObject created with numbers: " << num1 << " and " << num2 << std::endl;
    }

    void FindBiggerNumber(){
        std::cout << "The Bigger number is : " << (num1 > num2 ? num1 : num2) << std::endl;
    }

    ~BiggerNumber(){
        std::cout << "\nObject Destroyed" << std::endl;
    }

};


int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122" << std::endl;

    BiggerNumber<int> obj1(10, 12);
    obj1.FindBiggerNumber();

    BiggerNumber<float> obj2(2.35f, 1.02f);
    obj2.FindBiggerNumber();

    return 0;
}
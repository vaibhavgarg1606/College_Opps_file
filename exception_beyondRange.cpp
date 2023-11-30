#include <iostream>
#include <stdexcept>
#include <vector>



int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n" << std::endl;



    std::vector<int> arr = {1, 2, 3, 4};

    int index = 0;

    while(index != -1){
        std::cout << "\nEnter the index to access array: ";
        std::cin >> index;


        try{
            if(index >= 0 && index < arr.size()){
                std::cout << "\nElement at index " << index << ": " << arr[index] << std::endl;
            } else{
                throw std::out_of_range("Index Out of Range");
            }
        } catch (const std::out_of_range& e) {
            std::cerr << "[Exception caught]: " << e.what() << std::endl;
        }
    }

    return 0;

}



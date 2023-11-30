#include <iostream>
#include <fstream>


int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n" << std::endl;


    std::string file_loc;

    std::cout << "Enter File Location: ";
    std::cin >> file_loc;

    std::ifstream inputFile(file_loc.c_str());
    std::ofstream outputFile("output.txt");

    

    if(!inputFile.is_open() || !outputFile.is_open()){
        std::cerr << "[ERROR] opening files" << std::endl;
        return -1;
    }

    char c;
    std::cout << "Input File Content: " << std::endl;
    while(inputFile.get(c)){
        if(!std::isspace(static_cast<unsigned int>(c))){
            outputFile.put(c);
        }
        std::cout << c;
    }




    std::cout << "\n\nWhite spaces removed successfully!" << std::endl;



    inputFile.close();
    outputFile.close();
    
    std::ifstream outfile("output.txt");

    std::cout << "\nOutput File Content: " << std::endl;
    while(outfile.get(c)) std::cout << c;
    
    std::cout << std::endl;


    return 0;

}
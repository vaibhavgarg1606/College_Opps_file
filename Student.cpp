#include <iostream>
#include <string>
#include <fstream>

class Student{
public:
    std::string name;
    int age;
    char sex;
    float height;
    float weight;

    void InputInfo(){
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter sex: ";
        std::cin >> sex;
        std::cout << "Enter height: ";
        std::cin >> height;
        std::cout << "Enter weight: ";
        std::cin >> weight;
    } 

    void DisplayInfo(){
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Sex: " << sex << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }

};


int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n" << std::endl;


    std::ofstream outputFile("Student_Info.txt");
    Student student;
    student.InputInfo();

    outputFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    outputFile.close();


    std::ifstream inputFile("Student_Info.txt", std::ios::in | std::ios::binary);

    if(!inputFile){
        std::cerr << "[ERROR] opening file for reading!" << std::endl;
        return -1;
    }

    Student readStudent;

    inputFile.read(reinterpret_cast<char*>(&readStudent), sizeof(Student));

    std::cout << "\nReading From File." << std::endl;

    readStudent.DisplayInfo();
    inputFile.close();

    return 0;



}
#include <iostream>

constexpr int row = 3, col = 3;


class Mat{
private:
    int m_data[row][col];

public:

    void InputMat(){
        std::cout << "\nEnter the elements of " << row << "X" << col << " matrix: " << std::endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                std::cin >> m_data[i][j];
            }
        }
    }

    void display(){
        std::cout << "\nThe Matrix of order " << row << "X" << col << " is: " << std::endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                std::cout << m_data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Mat& operator*(Mat const& other){
        Mat res;

        for(int i = 0 ; i < row; i++)
            for(int j = 0 ; j < col; j++){
                res.m_data[i][j] = 0;
                for(int k = 0 ; k < row; k++)
                    res.m_data[i][j] += this->m_data[i][k] * other.m_data[k][j]; 
            }
        return res;
    }
};



int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122" << std::endl;


    Mat mat1;
    Mat mat2;

    mat1.InputMat();
    mat2.InputMat();

    auto mat3 = mat1 * mat2;

    mat3.display();
}



#include <iostream>




class List{
public:

    virtual void store(float value) = 0;
    virtual float retrieve() = 0;

};


constexpr int size = 3;

class Stack : public List{
private:
    float m_data[size];
    int top = -1;

public:

    void store(float value) override
    {
        if(top == size-1){
            std::cout << "[ERROR] Stack Overflow\n" << std::endl;;
        } else{
            m_data[++top] = value;
            std::cout << m_data[top] << " Stored in Stack." << std::endl;
        }
    }


    float retrieve() override
    {
        if(top == -1){
            std::cout << "[ERROR] Stack Underflow\n" << std::endl;
            return -1;
        }
        std::cout << m_data[top] << " Removed in Stack." << std::endl;

        return m_data[top--];

    }

};


class Queue : public List{
private:
    float m_data[size];
    int last = -1, first = -1;

public:

    void store(float value) override
    {
        if(last == size-1){
            std::cout << "[ERROR] Queue Overflow\n" << std::endl;;
        }else{
            if(last == -1){
                last = 0; first = 0;
            } else{
                last++;
            }
            m_data[last] = value;

            std::cout << m_data[last] << " Stored in Queue." << std::endl;
        }
    }


    float retrieve() override
    {
        if(first == -1 || first > last){
            std::cout << "[ERROR] Queue Underflow\n" << std::endl;
            return -1;
        }

        std::cout << m_data[first] << " Removed in Queue." << std::endl;

        return m_data[first++];
    }

};



int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n" << std::endl;


    Stack stack;
    Queue queue;

    stack.store(10);
    stack.store(20);
    stack.store(30);
    stack.store(40);
    stack.retrieve();
    stack.retrieve();
    stack.retrieve();
    stack.retrieve();
    queue.store(10);
    queue.store(20);
    queue.store(30);
    queue.store(40);
    queue.retrieve();
    queue.retrieve();
    queue.retrieve();
    queue.retrieve();

    return 0;

}

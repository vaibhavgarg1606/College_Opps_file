#include <iostream>
#include <cstring>


class String{
private:
    char* m_Buffer;
    unsigned int m_size;

public:

    String(){}

    String(char* str){
        m_size = strlen(str);
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, str, m_size);
        m_Buffer[m_size] = 0;
    }

    String(String& other) : m_size(other.m_size) {
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_size + 1);
    }

    ~String(){
        delete[] m_Buffer;
    }

    
        
    int string_len(){
        // int size = 0;
        // while (m_Buffer[size] != 0) size++;
        return m_size;
    }

    void operator = (const char* str){
        m_size = strlen(str);
        m_Buffer = new char[m_size + 1];
        memcpy(m_Buffer, str, m_size);
        m_Buffer[m_size] = 0;
    }

    bool operator == (const String& other){
        return !strcmp(this->m_Buffer, other.m_Buffer);
    }

    String operator+ (const String& other){


        String res;

        res.m_size = this->m_size + other.m_size;
        res.m_Buffer = new char[res.m_size + 1];

        int i = 0;
        while (this->m_Buffer[i] != 0){
            res.m_Buffer[i] = this->m_Buffer[i];
            i++;
        }

        int j = 0;
        while (other.m_Buffer[j] != 0){
            res.m_Buffer[i] = other.m_Buffer[j];
            i++; j++;
        }

        m_Buffer[m_size] = 0;

        return res;
        
    }

    String operator+ (const char* other){
        String res;

        res.m_size = this->m_size + strlen(other);
        res.m_Buffer = new char[res.m_size + 1];

        int i = 0;
        while (this->m_Buffer[i] != 0){
            res.m_Buffer[i] = this->m_Buffer[i];
            i++;
        }

        int j = 0;
        while (other[j] != 0){
            res.m_Buffer[i] = other[j];
            i++; j++;
        }

        m_Buffer[m_size] = 0;

        return res;

    }


    void operator += (const String& other){
        String res = *this + other;

        this->m_size = res.m_size;
        this->m_Buffer = new char[m_size + 1];
        memcpy(this->m_Buffer, res.m_Buffer, m_size + 1);
        
    }

    void operator += (const char* other){
        String res = *this + other;

        this->m_size = res.m_size;
        this->m_Buffer = new char[m_size + 1];
        memcpy(this->m_Buffer, res.m_Buffer, m_size + 1);
        
    }

    
    char* ToLower(){
        unsigned int size = 0;
        while(m_Buffer[size] != 0){
            m_Buffer[size] = tolower(m_Buffer[size]);
            size++;
        }
        return m_Buffer;
    }

    
    char* ToUpper(){
        unsigned int size = 0;
        while(m_Buffer[size] != 0){
            m_Buffer[size] = toupper(m_Buffer[size]);
            size++;
        }
        return m_Buffer;
    }


    friend std::ostream& operator<<(std::ostream& os, const String& str);
};



std::ostream& operator<<(std::ostream& os, const String& str){
    os << str.m_Buffer;
    return os;
}




int main(){

    std::cout << "\nName: Vaibhav Garg    | Enrollment NO : 05613203122\n" << std::endl;


    String str1 = "Hello ";
    String str2 = " World";

    // concatenation of strings
    String str3 = str1 + str2;

    std::cout << str1 << " + " << "str2 = " << str3 << std::endl;

    std::cout << "Lenght of str3 before assignment: " << str3.string_len() << std::endl;

    // assignment
    str3 = "Vaibhav Garg";

    std::cout << "After Assignment : str3 = " << str3 << std::endl;
    std::cout << "Lenght of str3 after assignment: " << str3.string_len() << std::endl;

    
    
    std::cout << "str3.ToLower() = " << str3.ToLower() << std::endl;
    std::cout << "str3.ToUpper() = " << str3.ToUpper() << std::endl;







}
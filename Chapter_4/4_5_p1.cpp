// Fix the bug that occurs when erasing more characters than the actual length of the string
#include <iostream>
#include <string.h>

class MyString{
    private:
    int memory_capacity;
    int string_length;
    char *string_content;

    public:
    MyString(char c);
    MyString(const char *str);
    MyString(const MyString& str);
    
    ~MyString();
    
    void println();
    MyString& erase(int loc, int num);
};

MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = 1;
}

MyString::MyString(const char *str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for(int i = 0; i < string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    memory_capacity = string_length;
    string_content = new char[string_length];
    for(int i = 0; i < string_length; i++) string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content;}

void MyString::println(){
    for(int i = 0; i < string_length; i++){
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

MyString& MyString::erase(int loc, int num){
    if(num < 0 || num > string_length) return *this;
    if(num + loc > string_length) num = string_length - loc;
    for(int i = loc + num; i < string_length; i++){
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}

int main(){
    MyString str1("abcdef");
    str1.println();

    str1.erase(2, 6);

    str1.println();
}
/* 여러가지 검색 알고리즘(KMP, Boyer - Moore) 들을 이용하는 find 함수를 만들어보세요 */
#include <iostream>
#include <string.h>

class MyString{
    private:
    int memory_capacity;
    int string_length;
    char *string_content;
    char *table;

    public:
    MyString(char c);
    MyString(const char *str);
    MyString(const MyString& str);
    
    ~MyString();
    
    void println();
    void FindKmp(MyString& pat);
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

void MyString::FindKmp(MyString& pat){
    // get kmp_table
    table = new char[pat.string_length] {0};
    int i = 0;
    for(int j = 1; j < pat.string_length; j++){
        while(i > 0 && pat.string_content[j] != pat.string_content[i]){
            i = table[i - 1];
        }
        if(pat.string_content[i] == pat.string_content[j]){
            i++;
            table[j] = i;
        }
    }
    // kmp search
    i = 0;
    for(int j = 0; j < string_length; j++){
        while(i > 0 && string_content[j] != pat.string_content[i]){
            i = table[i - 1];
        }
        if(pat.string_content[i] == string_content[j]){
            i++;
            if(i == pat.string_length){
                std::cout << " The index of found pattern is: " << j - i + 1<< std::endl;
                i = table[i - 1];
            }
        }
    }
    delete[] table;
}

int main(){
    MyString str1("hello everyone hello hi helle.");
    MyString str2("hello");
    str1.println();

    str1.FindKmp(str2);
    return 0;
}
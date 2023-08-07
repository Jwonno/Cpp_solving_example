/* 여러가지 검색 알고리즘(KMP, Boyer - Moore) 들을 이용하는 find 함수를 만들어보세요 */
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
    void find_KMP(MyString& str);
    void find_BadChar(MyString& str);
};

void computeLPSArray(char* pat, int M, int* lps);

void badCharHeuristic(char* str, int size, int badchar[256]);

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

void computeLPSArray(char* pat, int M, int* lps){
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < M){
        if(pat[len] == pat[i]){
            lps[i] = len;
            len++;
            i++;
        } else {
            if(len != 0){
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void MyString::find_KMP(MyString& str){
    const int M = str.string_length;
    char* pat = new char[M];
    for(int i = 0; i < M; i++) pat[i] = str.string_content[i];
    int* lps = new int[M] {0};
    computeLPSArray(pat, M, lps);
    
    int i = 0;
    int j = 0;
    while(i < string_length){
        if(pat[j] == string_content[i]){
            i++; j++;
        } 
        if(j == M) {
            std::cout << "The index of the Found string is: "
            << i - j << std::endl;
            j = lps[j - 1];
        }
        else if(i < string_length && pat[j] != string_content[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    delete[] pat;
    delete[] lps;
}

void badCharHeuristic(char* str, int size, int badchar[256]){
    int i;
    for(i = 0; i < 256; i++) badchar[i] = -1;
    for(i = 0; i < size; i++) badchar[(int)str[i]] = i;
}
void MyString::find_BadChar(MyString& str) {
    int m = str.string_length;
    int n = string_length;
    int badchar[256];
    char* pat = new char[m];
    for(int i = 0; i < m; i++) pat[i] = str.string_content[i];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s <= n - m){
        
        int j = m - 1;
        
        while(j >= 0 && pat[j] == string_content[s + j]) j--;
        
        if(j < 0){
            std::cout << "The index of the Found string is: " << s << std::endl;
            s += (s + m < n) ? m - badchar[string_content[s + m]] : 1;
        } else {
            s += std::max(1, j - badchar[string_content[s + j]]);
        }
    }
}

int main(){
    MyString str1("hello everyone hello hi helle.");
    MyString str2("hello");
    str1.println();
    str1.find_KMP(str2);

    str1.find_BadChar(str2);

    return 0;
}
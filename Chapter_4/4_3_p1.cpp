// 아래와 같은 문자열 클래스를 완성해보세요 
#include <iostream>

class string{
    char *str;
    int len;

    public:
     string(char c, int n);     // 문자 c 가 n 개 있는 문자열로 정의
     string(const char *s);     
     string(const string &s);   // copy constructor
     ~string();

     void add_string(const string &s);      // str 뒤에 s 를 붙인다.
     void copy_string(const string &s);     // str 에 s 를 복사한다.
     int strlen();                          // 문자열 길이 리턴
     
     void print_string();
};

string::string(char c, int n){
    len = 0;
    str = new char[n + 1];
    for(int i=0; i<n; i++){
        len++;
        str[i] = c;
    }
}

string::string(const char *s){
    len = 0;
    for(int i=0; s[i]; i++){len++;}
    str = new char[len + 1];
    for(int i=0; i<len; i++){
        str[i] = s[i];
    }
}

string::string(const string &s){
    len = s.len;
    str = new char[len + 1];
    for(int i=0; i<len; i++){
        str[i] = s.str[i];
    }
}

string::~string(){
    if(str) delete[] str;
}

void string::add_string(const string &s){
    delete[] str;
    len = s.len;
    str = new char[len + s.len+1];
    for(int i=0; i<s.len; i++){
        str[len+i] = s.str[i];
    }
}

void string::copy_string(const string &s){
    delete[] str;
    len = s.len;
    str = new char[s.len + 1];
    for(int i=0; i<s.len; i++){
        str[i] = s.str[i];
    }
}

int string::strlen(){return len;}

void string::print_string(){
    std::cout << str << std::endl;
}



int main(){
    string str1('a', 5);
    string str2(str1);
    string str3('b', 7);
    string str4('c', 2);

    str1.print_string();
    str2.print_string();
    str3.print_string();
    str4.print_string();

    std::cout << std::endl;

    str2.add_string(str4);
    str3.copy_string(str1);
    str4.copy_string(str1);

    str3.print_string();
    str4.print_string();

    return 0;
}
// �Ʒ��� ���� ���ڿ� Ŭ������ �ϼ��غ����� 
#include <iostream>

class string{
    char *str;
    int len;

    public:
     string(char c, int n);     // ���� c �� n �� �ִ� ���ڿ��� ����
     string(const char *s);     
     string(const string &s);   // copy constructor
     ~string();

     void add_string(const string &s);      // str �ڿ� s �� ���δ�.
     void copy_string(const string &s);     // str �� s �� �����Ѵ�.
     int strlen();                          // ���ڿ� ���� ����
     
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
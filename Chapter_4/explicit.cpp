#include <iostream>

class MyString{
    char *string_content;
    int string_length;

    int memory_capacity;

    public:
    // Pre-allocated up to the capacity.
    explicit MyString(int capacity);

    // constructor from string
    MyString(const char *str);

    // copy string
    MyString(const MyString& str);

    // destructor
    ~MyString();

    int length() const;
};

MyString::MyString(int capacity){
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity: " << capacity << std::endl;
}

MyString::MyString(const char *str){
    string_length = 0;
    while(str[string_length++]){}
    string_content = new char[string_length];
    memory_capacity = string_length;
    for(int i = 0; i < string_length; i++)  string_content[i] = str[i];
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];
    for(int i = 0; i < string_length; i++)  string_content[i] = str.string_content[i];
}

MyString::~MyString()   { delete[] string_content; }
int MyString::length() const { return string_length;}

void DoSomethingWithString(MyString s){}

int main(){

    // DoSomethingWithString(3);
    MyString s = "abc";     // MyString s("abc");
    // MyString s = 5;      // MyString s(5);
    return 0; 
}

// If the function is called in this format... 
// DoSomethingWithString("abc");

// The C++ compiler thinks about how to convert "abc" into the MyString type.
// Because C++ compliler is quite intelligent and there was 'MyString(const char *str)' 

// So DoSomethingWithString("abc"); is trasformed into DoSomethingWithString(MyString("abc"));
// and gets complied.

// The transformation is called 'implicit conversion'.

// But 'implicit conversion' is not always good for users.

// For example, how about this statement?
// DoSomethingWithString(3);

// Users are likely to misuse the function.
// But compiler don't consider this statement as error.

// Because, there was 'MyString(int capacity)' 
// So DoSomethingWithString(3); is trasformed into DoSomethingWithString(MyString(3));

// But you can instruct the compiler not to allow unwanted implicit conversions.
// by keyword 'explicit'.

// 'explicit' also allow constructor not to be called in the form of 'copy constructor'.
// For example,  
// MyString s = "abc";  // approval
// MyString s = 5       // complie error
#include <iostream>
#include <string.h>

class MyString {
    private:
    char* string_content;   // Pointer indicating Data of string
    int string_length;      // Length of String
    int memory_capacity;    // The current allocated memory space size

    public:
    // Constructor by one character
    MyString(char c);

    // Construct by string
    MyString(const char *str);

    // Copy Constructor
    MyString(const MyString& str);

    // Destructor
    ~MyString();

    // functions(As inner member variations are never changed, so we defined functions as 'const')
    // Return length of string
    int length() const;

    // Print contents
    void print() const;
    void println() const;   // include '\n'

    // Assign
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    // Return capacity
    int capacity();
    
    // Reserve the size of memory to be allocated in advance 
    void reserve(int size);

    // Return a character at a specific position
    char at(int i) const;

    // Insert
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char *str);
    MyString& insert(int loc, char c);

    // Erase
    MyString& erase(int loc, int num);
};

MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}

MyString::MyString(const char *str){
    string_length = strlen(str);
    string_content = new char[string_length];
    for(int i = 0; i < string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];
    for(int i = 0; i < string_length; i++) string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length;}
void MyString::print() const {
    for (int i = 0; i < string_length; i++){
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i < string_length; i++){
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str){
    if(str.string_length > memory_capacity){
        // Reallocating
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    // else: We can avoid inefficient operations by not reallocating memory.
        for(int i = 0; i < string_length; i++){
            string_content[i] = str.string_content[i];
        }
    string_length = str.string_length;
    return *this;
}

MyString& MyString::assign(const char* str){
    int str_length = strlen(str);
    if(str_length > memory_capacity){
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for(int i = 0; i < str_length; i++){
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}

int MyString::capacity() { return memory_capacity; }

void MyString::reserve(int size){
    if(size > memory_capacity){
        char *prev_string_content = string_content;

        string_content = new char [size];
        memory_capacity = size;

        for(int i = 0; i < string_length; i++){
            string_content[i] = prev_string_content[i];

        }
        delete[] prev_string_content;
    }
    // else
    // If the size of the memory space being allocated is smaller 
    // than the current allocated size, there is no need to allocate it.
}

char MyString::at(int i) const{
        // if i exceed length, return origin string(*this)
        if(i >= string_length || i < 0) return NULL;
        else return string_content[i];
    }

MyString& MyString::insert(int loc, const MyString& str){
    if(loc < 0 || loc > string_length) return *this;
    if(string_length + str.string_length > memory_capacity){
        // Reallocating
        // To avoid frequent allocation/deallocation during the insert operation, preallocate memory
        if(memory_capacity * 2 > string_length + str.string_length){
            memory_capacity *=2;
        }
        else{
            memory_capacity = string_length + str.string_length;
        }

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // Copy the content up to just before the point of insertion
        int i;
        for(i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        // Insert the newly added string
        for(int j = 0; j < str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        // Copy end part of origin string
        for(;i < string_length; i++){
            string_content[i + str.string_length] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }
    // else 
    // If there is enough memory capacity, there is no need to reallocating
    for(int i = string_length - 1; i >= loc; i--){
        // Copy the content to the end part
        // ex) b,a,n,a,n,a,_,_,_ -> b,a,n,a,n,a,_,_,a
        //     b,a,n,a,n,a,_,_,a -> b,a,n,a,n,a,_,n,a
        //     b,a,n,a,n,a,_,n,a -> b,a,n,a,n,a,a,n,a
        string_content[str.string_length + i] = string_content[i];
    }
    // Insert the newly added string
    for(int i = 0; i < str.string_length; i++)  string_content[i + loc] = str.string_content[i];
    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str){
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c){
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num){
    if(num < 0 || num > string_length) return *this;
    // else
    // Erasing essentially involves pulling the characters from behind to the front
     for(int i = loc + num; i <string_length; i++){ 
        string_content[i - num] = string_content[i];
     }
     string_length -= num;
     // No matter what information comes after string_length, 
     // you don't have to worry much about it
     return *this;
}

int main(){
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();

    MyString str3("very very very long string");
    str3.reserve(30);

    std::cout << "Capacity: " << str3.capacity() << std::endl;
    std::cout << "String Length: " << str3.length() << std::endl;
    str3.println();

    std::cout << "2'nd character: " << str3.at(1) << std::endl;

    str3.insert(5, str2);
    str3.println();

    MyString str4("abcde");
    str4.erase(2, 2);
    str4.println();
    
    return 0;
}
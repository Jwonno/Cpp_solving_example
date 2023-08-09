#include <iostream>

class A{
    int data_;
    mutable int data_m;
    public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const {
        // data_ = x;      // In 'const function', member variables cannot be changed.
        data_m = x;     // If member variables are declared as mutable, their values can be changed even in const functions
    }

    void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main(){
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}
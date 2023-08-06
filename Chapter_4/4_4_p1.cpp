/* "copy constructor" 를 몇 번이나 출력할까요? */
#include <iostream>

class A {
    int x;

    public:
    A(int c) : x(c){}
    A(const A& a) {
        x = a.x;
        std::cout << "copy constructor" << std::endl;
    }
};

class B{
    A a;

    public:
    B(int c) : a(c) {}
    B(const B& b) : a(b.a) {}
    A get_A() {
        A temp(a);
        return temp;
    }
};

int main() {
    B b(10);

    std::cout << "--------" << std::endl;
    A a1 = b.get_A();
}
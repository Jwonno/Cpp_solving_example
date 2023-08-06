// Return Reference Function
#include <iostream>

class A {
    int x;

    public:
    A(int c) : x(c) {}

    // return reference
    int& access_x() { return x; }
    
    // return integer
    int get_x() { return x; }

    void show_x() { std::cout << x << std::endl; }
};

int main(){
    A a(5);
    a.show_x();

    int& c = a.access_x();
    // 레퍼런스 c 는 x 의 레퍼런스를 받았으므로,
    // c 의 값을 바꾸는 것은 a 의 x 값을 바꾸는 것과 동일하다.
    c = 4;
    a.show_x();

    int d = a.access_x();
    // 단순히 d 에는 x 의 값이 들어가게 된다.
    d = 3;
    a.show_x();

    // error
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();
    // 레퍼런스가 아닌 타입을 리턴하는 경우에는 '값'의 복사가 이루어지기 때문에
    // 임시 객체가 생성되는데 임시객체의 레퍼런스를 가질 수 없기 때문이다.

    int f = a.get_x();
    // 이것 역시 단순히 f 에 x 의 값이 들어가게된다.
    f = 1;
    a.show_x();

    // 한가지 예시로 a.access_x() = 3; 이 문장은 a.x = 3; 과 동일한 문장이 된다.
    // 반면 a.get() = 3; 이 문장은 오류가 그 이유는 임시객체에 대입을 하게되는 모순 때문이다. 

    return 0;
}
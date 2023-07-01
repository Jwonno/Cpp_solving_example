/* 여러가지 참조자 예시들 */
#include <iostream>

int main(){
    int x;
    int& y = x;
    int& z = y;
    // z 는 참조자의 참조자가 되는 것은 아니다.
    // int&& z; 는 불가능한 문장(C++ 문법 상 참조자의 참조자를 만드는 것은 금지)
    // 따라서 z 또한 x 의 참조자가 된다.
    x = 1;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    y = 2;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    z = 3;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

    return 0;
}
// 번외로 cin 이 scanf() 와 다르게 인자로 변수에 & 를 안 붙이는 이유도 
// 레퍼런스로 변수 인자를 받기 때문이다.
// ex) scanf("%d", &data);
//     std::cin << data;    
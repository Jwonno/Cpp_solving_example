#include <iostream>

int change_val(int *p){
    *p = 3;

    return 0;
}
int main(){
    int number = 5;

    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;

    //포인터 대신 C++의 참조자(reference)
    int a = 3;
    int &another_a = a;
    //int형 변수의 참조자는 int& , double형 변수의 참조자는 double& 처럼 데이터의 타입 뒤에 &를 붙이면 참조자를 정할 수 있다.
    //포인터 타입의 참조자는 int*& 과 같이 동일한 방식으로 정할 수 있다.
    another_a = 5;
    //another_a 가 a 의 참조자이므로 another_a 에 수행하는 작업은 a 에 작업을 하는 것과 마찬가지이다.
    std::cout << "a: "<< a << std::endl;
    //따라서 "a: 3" 이 아닌 "a: 5" 가 출력된다.
    std::cout << "another_a: "<< another_a << std::endl;

    // Reference의 특징_1
    // 레퍼런스는 반드시 선언할 시에 어느 것을 참조하는지 명시적으로 지정해야한다.
    // 예를 들어 포인터 변수의 경우 int *parr; 은 가능하지만, 
    // 레퍼넌스는 int& another_a; 와 같은 문장이 불가능하다.

    // Reference의 특징_2
    // 레퍼런스가 한 번 어느 것을 참조하면 다른 어떤 것의 참조자가 될 수 없다.
    // 예를 들어 
    int a2;
    int& another_a2 = a2;
    int b2 = 3;
    another_a2 = b2;
    // 위와 같은 문장은 another_a2 가 b2 를 참조하는 것이 아닌 a2 에 b2 값을 대입하라는 것이다.
    // 즉 a2 = b2; 와 동치인 문장이 된다.
    // 반면에 포인터의 경우
    int *p = &a2;    //p 는 a2 를 가리킨다.
    p = &b2;         //p 는 a 가 아닌 b3 를 가리킨다.

    // Reference의 특징_3
    // 레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.
    // 예를 들어 포인터의 경우
    int a3 = 10;
    int *p2 = &a3;   //p2 는 메모리 상에서 8 바이트를 차지하게 된다.
    //반면에 레퍼런스의 경우
    int &another_a2 = a3;   //another_a2 를 위해 굳이 메모리 상에 공간을 할당할 필요가 없다!

    return 0;
}

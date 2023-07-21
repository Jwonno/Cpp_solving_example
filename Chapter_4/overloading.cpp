/* 함수의 오버로딩 */
// C++ 에서는 같은 이름의 함수 여러개 존재할 수 있다.(함수의 이름에 과부하가 걸려도 상관이 없다.)
// 사용하는 인자를 보고 구분
#include <iostream>

void print(int x){ std::cout << "int: " << x << std::endl;}
void print(char x){ std::cout << "char: " << x << std::endl;}
void print(double x){ std::cout << "double: " << x << std::endl;}

int main(){
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);

    return 0;
}
// 만약 void print(char x){...} 가 없다면 print(b) 는 정확히 일치하는 타입이 없다.

// 따라서 아래와 같은 형변환을 통해서 일치하는 함수를 찾는다.
// 1 단계
//  - Char, unsigned char, short 는 int 로 변환된다.

//  - Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.

//  - Float 은 double 로 변환된다.

//  - Enum 은 int 로 변환된다. 


// 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해서 일치하는 함수를 찾는다.
// 2 단계
//  - 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)

//  - Enum 도 임의의 숫자 타입으로 변환된다 (예를 들어 Enum -> double)

//  - 0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다

//  - 포인터는 void 포인터로 변환된다.


// 그러면 위와 같은 형변환 단계에서 일치하는 함수가 2 가지 이상이면 어떻게 될까?
// 예를 들어 만약 위의 코드에서 void print(double x){...} 가 사라진다면?
// 먼저 1 단계에서 형변환은 이루어지지 않고 2 단계 형변환으로 넘어간다.
// 이때 "임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다." 에 의해 형변환이 이루어지는데,
// double -> int, double -> char 두 가지 모두 가능하므로 
// 둘 중 어느 함수를 호출해야되는지 명시되어있지 않기 때문에
// 오류가 발생하게 된다.

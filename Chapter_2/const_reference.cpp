/* 상수에 대한 참조자 */
#include <iostream>
int main(){
    // int &ref = 4;
    // 위와 같은 문장으로 실행하면 오류가 난다.
    // C++ 문법 상 상수 리터럴을 일반적인 레퍼런스가 참조하는 것은 금지되어있기 때문이다.
    // 따라서 아래와 같이 상수 참조자로 선언을 해야한다.
    const int &ref = 4;
    int a = ref;
    // int a = 4; (equivalent sentence)
    std::cout << ref << std::endl;

    return 0;
}
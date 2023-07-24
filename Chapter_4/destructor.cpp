#include <iostream>
#include <string.h>

class Test {
    private:
        char c;

    public:
        Test(char _c){
            c = _c;
            std::cout << "생성자 호출" << c << std::endl;   // 어떤 객체가 생성되고 소멸되는지 확인하기위한 출력문
        }
        ~Test(){
            std::cout << "소멸자 호출" << c << std::endl;
        }
};
void simple_function(){ Test b('b'); }
int main(){
    Test a('a');
    simple_function();
    return 0;
}

// b 는 simple_function() 의 지역 객체이기 때문에 simple_function() 이 종료됨과 동시에 b 역시 소멸되게 된다.
// 따라서 b 의 소멸자가 호출됨
// simple_function() 함수가 종료되고 main() 함수가 종료될 때 a 도 마찬가지로 객체가 소멸되면서 소멸자가 호출된다.
// 따라서 생성자와 소멸자의 순서가 a -> b -> b -> a 이다.
// default constructor 가 있는 것처럼 default destructor 가 존재한다. 물론 아무런 작업도 수행하지 않는다.
// 소멸자가 필요 없는 클래스라면 굳이 소멸자를 따로 사용할 필요는 없다.

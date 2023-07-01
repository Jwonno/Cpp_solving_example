/* 함수 인자로 레퍼런스 받기 */
#include <iostream>

int change_val(int &p){
    // p 가 정의되는 순간은 change(number) 로 호출할 때 이므로
    // 사실상 int &p = number; 가 실행되는 것과 마찬가지이다.
    p = 3; 

    return 0;
}

int main(){
    int number = 5;
    
    std::cout << number << std::endl;
    change_val(number);
    //포인터가 인자일 때와는 다르게 변수를 그대로 인자로 전달한다.
    std::cout << number << std::endl;

    return 0;
}
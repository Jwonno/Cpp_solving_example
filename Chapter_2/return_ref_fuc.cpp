/* 레퍼런스를 return 하는 함수 */
/*//CASE_1 (지역변수의 레퍼런스를 리턴)
#include <iostream>

int& function(){
    int a = 2;
    return a;
}

int main(){
    int b = function();
    b = 3;
    return 0;
}
// 위 코드는 실제로 실행해보면 오류가 발생한다.
// 왜냐하면 function() 의 return type 은 int& 이므로 참조자를 리턴하는데,
// 문제는 function() 안에 있는 a 가 함수의 리턴과 함께 사라져버리기 때문이다.
// 위 코드를 다시 써보면

// int& function(){int a = 2;return a;}  ---->  int& ref = a; 
// (a가 메모리 상에서 사라짐)
// int b = function();  ---->  int b = ref;

// 이와 같은데 a 가 사라지면서 ref의 본체는 사라진 셈이 되고,
// 실행 시에 오류가 발생하는 것이다.

// 이렇게 참조하던 본체가 사라진 레퍼런스를 댕글링 레퍼런스(Dangling reference)라고 부른다.

// 따라서 위 처럼 레퍼런스를 리턴하는 함수에서는
// 지역 변수의 레퍼런스를 리턴하지 않도록 조심해야 한다.*/

/*//CASE_2 (외부변수의 레퍼런스를 리턴)
#include <iostream>

int& function(int& a){
    a = 5;
    return a;
    // 인자로 받은 레퍼런스를 그대로 리턴하고 있다.
}

int main(){
    int b = 2;
    int c = function(b);
    // function() 이 리턴한 참조자는 아직 생존해 있는 b 를 계속 참조하고 있다.
    return 0;
}
// 이렇게 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관 없이 
// 딱 한 번의 주소값 복사로 전달이 끝나서 매우 효율적이다.*/

/*//CASE_3-1 (참조자가 아닌 값을 리턴하는 함수를 참조자로 받기)
#include <iostream>

int function(){
    int a = 5;
    return a;
}

int main(){
    int& c = function();        // 오류 발생
    // a 가 사라지면서 c 가 Dangling reference 가 되어버린다.
    return 0;
}*/

/*//CASE_3-2(예외상황)
#include <iostream>

int function() {
    int a = 5;
    return a;
}

int main(){
    const int& c = function();
    std::cout << "c: " << c << std::endl;
    return 0;
}
// "c: 5" 가 출력이 되는 이유는?
// 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장된다.
// 연장되는 기간은 해당 레퍼런스가 사라질 때 까지다.*/
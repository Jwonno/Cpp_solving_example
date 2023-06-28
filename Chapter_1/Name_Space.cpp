#include <iostream>     //iostream 헤더 파일을 include 하고 있다.
// iostream 헤더 파일은 C++ 표준 입출력에 필요한 것들을 포함하고 있다.
// ex) std::cout, std::endl,... 
/*int main(){
    std::cout << "Hello World!!" << std::endl;      
    //cout 앞에 붙어 있는 std 는 C++표준 라이브러리의 모든 함수, 객체 등이 정의된 이름공간(namespace) 이다.
    //같은 이름이더라도 이름 공간이 다르면 다른 것으로 취급한다.
    return 0;
}*/

//이름 공간을 정의하는 방법은 아래와 같다.
/*//두 헤더파일 header1.h , header2.h 를 만들어 놓고 포함했을 때
#include "header1.h"
#include "header2.h"
//header1의 이름공간에 소속되어 있을 때는
namespace header1 {
    int func(){
        foo();              //알아서 header1::foo() 가 실행된다.
        header2::foo();     //header2::foo() 가 실행된다.
    }
}  
//위처럼 어떠한 이름공간에 소속되어 있다면 이름 공간을 지정하지 않아도 되지만
//만약 어떠한 이름공간에도 소속되지 않는다면
int func(){
    header1::foo();     //원하는 이름공간을 명시적으로 지정해줘야 한다.
}

//만약 기본적으로 header1 이름 공간 안에 정의된 모든 것들을 header1:: 없이 사용하고 싶다면
using namespace header1;
int main(){
    header2::foo();  //header2 에 있는 함수를 호출
    bar();           //header1 에 있는 함수를 호출
}
*/
/*//따라서 위의 예제 코드에서 이름공간 std::를 생략하고 싶다면 아래와 같이 코드를 수정하면 된다.
using namespace std;

int main() {
    cout << "Hello, World!!" <<endl;
    return 0;
}
//하지만 using namespace std; 와 같이 선언하는 것은 권장되지 않는다.
//왜냐하면 std 에 이름이 겹치는 함수를 만들게 된다면, 오류가 발생하기 때문이다.
//따라서 std:: 를 직접 앞에 붙여서 명시적으로 지정해주는 것이 혹시 모를 충돌로부터 보호하는데 좋다.

//std::cout << "출력할 것1" << "출력할 것2" <<.....<< "출력할 것n";
//endl 은 화면에 출력해주는 '함수' 이지만 
//std::cout << std::endl; 이라고 쓰면 '화면에 엔터를 하나 출력' 하는 기능을 한다.
*/
/*이름 없는 이름 공간*/

namespace{
    //이 함수는 이 파일 안에서만 사용할 수 있다.
    //C언어의 static int OnlyInThisFile() 과 동일하다.
    int OnlyInThisFile(){}

    //이 변수 역시 static int x 와 동일하다.
    int only_in_this_file = 0;
}

int main(){
    OnlyInThisFile();
    only_in_this_file = 3;
}
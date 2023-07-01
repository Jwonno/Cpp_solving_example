/*레퍼런스의 배열*/
/*#include <iostream>

int main(){
    // int a, b;
    // int &arr[2] = {a, b}; ----> illegal
    // C++ 규정에 의하면 
    // There shall be no references to references, 레퍼런스의 레퍼런스와
    // no arrays of references, 레퍼런스의 배열과
    // and no pointers to references 그리고 레퍼런스의 포인터는 존재할 수 없다. 
    // 라고 명시되어 있다.

    // 안되는 이유는?
    // 문법 상 배열의 이름은 첫번째 원소의 주소값으로 변환이 될 수 있어야한다.
    // arr[0], arr[1] 이 *arr, (*arr+1) 로 바뀌어서 처리될 수 있기 때문이다.
    // 이렇게 주소값이 존재한다는 것은 해당 원소가 메모리 상에서 존재한다는 의미와 같다.
    // 하지만 레퍼런스는 메모리 상에서 공간을 차지하지 않는다.(특별한 경우를 제외하고)
    // 따라서 레퍼런스들의 배열은 금지되어있는 것이다.

    return 0;
}*/

/* 배열들의 레퍼런스 */
#include <iostream>

int main(){
    int arr[3] = {1, 2, 3};
    int (&ref)[3] = arr;
    // 배열의 레퍼런스인 경우 포인터와는 다르게 반드시 배열의 크기를 명시해야 한다.
    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;

    // 2차원 배열
    int arr2[3][2] = {1, 2, 3, 4, 5, 6};
    int (&ref2)[3][2] = arr2;

    return 0;
}
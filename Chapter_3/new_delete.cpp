/* new 와 delete 의 사용 */
#include <iostream>
/*
int main(){
    int *p = new int;       // c 언어에서 malloc 함수를 이용한 동적할당과 비슷한 사용법이다.
    *p = 10;

    std::cout << *p <<std::endl;

    delete p;               // 동적할당에서의 free() 와 같이 사용이 끝난 공간은 해제해주어야한다.
    return 0;
}
*/

// 지역 변수 delete 하기(경고가 발생)
/*int main(){
    int a = 4;

    delete &a;
    return 0;
}
*/

// new 로 배열 할당하기
int main(){
    int arr_size;
    std::cout << "Enter the size: ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for(int i=0; i<arr_size; i++){
        std::cin >> list[i];
    }
    for(int i=0; i<arr_size; i++){
        std::cout << i+1 << "th element of list: " << list[i] << std::endl;
    }
    delete[] list;  // 공간을 해제할 때, new int[] -> delete[] var 과 같이 형태를 맞춰야한다.
    return 0;
}
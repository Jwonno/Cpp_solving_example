/* new �� delete �� ��� */
#include <iostream>
/*
int main(){
    int *p = new int;       // c ���� malloc �Լ��� �̿��� �����Ҵ�� ����� �����̴�.
    *p = 10;

    std::cout << *p <<std::endl;

    delete p;               // �����Ҵ翡���� free() �� ���� ����� ���� ������ �������־���Ѵ�.
    return 0;
}
*/

// ���� ���� delete �ϱ�(��� �߻�)
/*int main(){
    int a = 4;

    delete &a;
    return 0;
}
*/

// new �� �迭 �Ҵ��ϱ�
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
    delete[] list;  // ������ ������ ��, new int[] -> delete[] var �� ���� ���¸� ������Ѵ�.
    return 0;
}
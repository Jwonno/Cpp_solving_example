/* �Լ� ���ڷ� ���۷��� �ޱ� */
#include <iostream>

int change_val(int &p){
    // p �� ���ǵǴ� ������ change(number) �� ȣ���� �� �̹Ƿ�
    // ��ǻ� int &p = number; �� ����Ǵ� �Ͱ� ���������̴�.
    p = 3; 

    return 0;
}

int main(){
    int number = 5;
    
    std::cout << number << std::endl;
    change_val(number);
    //�����Ͱ� ������ ���ʹ� �ٸ��� ������ �״�� ���ڷ� �����Ѵ�.
    std::cout << number << std::endl;

    return 0;
}
/* ����� ���� ������ */
#include <iostream>
int main(){
    // int &ref = 4;
    // ���� ���� �������� �����ϸ� ������ ����.
    // C++ ���� �� ��� ���ͷ��� �Ϲ����� ���۷����� �����ϴ� ���� �����Ǿ��ֱ� �����̴�.
    // ���� �Ʒ��� ���� ��� �����ڷ� ������ �ؾ��Ѵ�.
    const int &ref = 4;
    int a = ref;
    // int a = 4; (equivalent sentence)
    std::cout << ref << std::endl;

    return 0;
}
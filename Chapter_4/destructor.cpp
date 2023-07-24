#include <iostream>
#include <string.h>

class Test {
    private:
        char c;

    public:
        Test(char _c){
            c = _c;
            std::cout << "������ ȣ��" << c << std::endl;   // � ��ü�� �����ǰ� �Ҹ�Ǵ��� Ȯ���ϱ����� ��¹�
        }
        ~Test(){
            std::cout << "�Ҹ��� ȣ��" << c << std::endl;
        }
};
void simple_function(){ Test b('b'); }
int main(){
    Test a('a');
    simple_function();
    return 0;
}

// b �� simple_function() �� ���� ��ü�̱� ������ simple_function() �� ����ʰ� ���ÿ� b ���� �Ҹ�ǰ� �ȴ�.
// ���� b �� �Ҹ��ڰ� ȣ���
// simple_function() �Լ��� ����ǰ� main() �Լ��� ����� �� a �� ���������� ��ü�� �Ҹ�Ǹ鼭 �Ҹ��ڰ� ȣ��ȴ�.
// ���� �����ڿ� �Ҹ����� ������ a -> b -> b -> a �̴�.
// default constructor �� �ִ� ��ó�� default destructor �� �����Ѵ�. ���� �ƹ��� �۾��� �������� �ʴ´�.
// �Ҹ��ڰ� �ʿ� ���� Ŭ������� ���� �Ҹ��ڸ� ���� ����� �ʿ�� ����.

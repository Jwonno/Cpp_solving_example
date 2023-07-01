/* ���۷����� return �ϴ� �Լ� */
/*//CASE_1 (���������� ���۷����� ����)
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
// �� �ڵ�� ������ �����غ��� ������ �߻��Ѵ�.
// �ֳ��ϸ� function() �� return type �� int& �̹Ƿ� �����ڸ� �����ϴµ�,
// ������ function() �ȿ� �ִ� a �� �Լ��� ���ϰ� �Բ� ����������� �����̴�.
// �� �ڵ带 �ٽ� �Ẹ��

// int& function(){int a = 2;return a;}  ---->  int& ref = a; 
// (a�� �޸� �󿡼� �����)
// int b = function();  ---->  int b = ref;

// �̿� ������ a �� ������鼭 ref�� ��ü�� ����� ���� �ǰ�,
// ���� �ÿ� ������ �߻��ϴ� ���̴�.

// �̷��� �����ϴ� ��ü�� ����� ���۷����� ��۸� ���۷���(Dangling reference)��� �θ���.

// ���� �� ó�� ���۷����� �����ϴ� �Լ�������
// ���� ������ ���۷����� �������� �ʵ��� �����ؾ� �Ѵ�.*/

/*//CASE_2 (�ܺκ����� ���۷����� ����)
#include <iostream>

int& function(int& a){
    a = 5;
    return a;
    // ���ڷ� ���� ���۷����� �״�� �����ϰ� �ִ�.
}

int main(){
    int b = 2;
    int c = function(b);
    // function() �� ������ �����ڴ� ���� ������ �ִ� b �� ��� �����ϰ� �ִ�.
    return 0;
}
// �̷��� ���۷����� �����ϰ� �ȴٸ� ���۷����� �����ϴ� Ÿ���� ũ��� ��� ���� 
// �� �� ���� �ּҰ� ����� ������ ������ �ſ� ȿ�����̴�.*/

/*//CASE_3-1 (�����ڰ� �ƴ� ���� �����ϴ� �Լ��� �����ڷ� �ޱ�)
#include <iostream>

int function(){
    int a = 5;
    return a;
}

int main(){
    int& c = function();        // ���� �߻�
    // a �� ������鼭 c �� Dangling reference �� �Ǿ������.
    return 0;
}*/

/*//CASE_3-2(���ܻ�Ȳ)
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
// "c: 5" �� ����� �Ǵ� ������?
// ���������� ��� ���۷����� ���ϰ��� �ް� �Ǹ� �ش� ���ϰ��� ������ ����ȴ�.
// ����Ǵ� �Ⱓ�� �ش� ���۷����� ����� �� ������.*/
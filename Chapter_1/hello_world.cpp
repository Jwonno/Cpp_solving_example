#include <iostream>     //iostream ��� ������ include �ϰ� �ִ�.
// iostream ��� ������ C++ ǥ�� ����¿� �ʿ��� �͵��� �����ϰ� �ִ�.
// ex) std::cout, std::endl,... 
/*int main(){
    std::cout << "Hello World!!" << std::endl;      
    //cout �տ� �پ� �ִ� std �� C++ǥ�� ���̺귯���� ��� �Լ�, ��ü ���� ���ǵ� �̸�����(namespace) �̴�.
    //���� �̸��̴��� �̸� ������ �ٸ��� �ٸ� ������ ����Ѵ�.
    return 0;
}*/

//�̸� ������ �����ϴ� ����� �Ʒ��� ����.
/*//�� ������� header1.h , header2.h �� ����� ���� �������� ��
#include "header1.h"
#include "header2.h"
//header1�� �̸������� �ҼӵǾ� ���� ����
namespace header1 {
    int func(){
        foo();              //�˾Ƽ� header1::foo() �� ����ȴ�.
        header2::foo();     //header2::foo() �� ����ȴ�.
    }
}  
//��ó�� ��� �̸������� �ҼӵǾ� �ִٸ� �̸� ������ �������� �ʾƵ� ������
//���� ��� �̸��������� �Ҽӵ��� �ʴ´ٸ�
int func(){
    header1::foo();     //���ϴ� �̸������� ��������� ��������� �Ѵ�.
}

//���� �⺻������ header1 �̸� ���� �ȿ� ���ǵ� ��� �͵��� header1:: ���� ����ϰ� �ʹٸ�
using namespace header1;
int main(){
    header2::foo();  //header2 �� �ִ� �Լ��� ȣ��
    bar();           //header1 �� �ִ� �Լ��� ȣ��
}
*/
/*//���� ���� ���� �ڵ忡�� �̸����� std::�� �����ϰ� �ʹٸ� �Ʒ��� ���� �ڵ带 �����ϸ� �ȴ�.
using namespace std;

int main() {
    cout << "Hello, World!!" <<endl;
    return 0;
}
//������ using namespace std; �� ���� �����ϴ� ���� ������� �ʴ´�.
//�ֳ��ϸ� std �� �̸��� ��ġ�� �Լ��� ����� �ȴٸ�, ������ �߻��ϱ� �����̴�.
//���� std:: �� ���� �տ� �ٿ��� ��������� �������ִ� ���� Ȥ�� �� �浹�κ��� ��ȣ�ϴµ� ����.

//std::cout << "����� ��1" << "����� ��2" <<.....<< "����� ��n";
//endl �� ȭ�鿡 ������ִ� '�Լ�' ������ 
//std::cout << std::endl; �̶�� ���� 'ȭ�鿡 ���͸� �ϳ� ���' �ϴ� ����� �Ѵ�.
*/
/*�̸� ���� �̸� ����*/

namespace{
    //�� �Լ��� �� ���� �ȿ����� ����� �� �ִ�.
    //C����� static int OnlyInThisFile() �� �����ϴ�.
    int OnlyInThisFile(){}

    //�� ���� ���� static int x �� �����ϴ�.
    int only_in_this_file = 0;
}

int main(){
    OnlyInThisFile();
    only_in_this_file = 3;
}
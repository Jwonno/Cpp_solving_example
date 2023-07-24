/* Photon Cannon */
/*
#include <iostream>
#include <string.h>

class Photon_Cannon{
    int hp, shield;
    int damage;
    int coord_x, coord_y;

    public:
     Photon_Cannon(int x, int y);
     Photon_Cannon(const Photon_Cannon& pc);    // Copy Constructor
     // standard definition of Copy Constructor
     // class T{...T(const T& a);...};
     // �� �ٸ� T �� ��ü a �� const references �� �޴� �ٴ� ��

     void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    std::cout << "���� ������ ȣ�� !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    // pc.coord_x = 3;  const reference �� ���ڸ� �޾ұ� ������ �Ұ��� !
}
Photon_Cannon::Photon_Cannon(int x, int y){
    std::cout << "������ ȣ��" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

void Photon_Cannon::show_status(){
    std::cout << "*** Photon Cannon ***" << std::endl;
    std::cout << "Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2;    
    // �� ������ Photon_Cannon pc3(pc2); �� ������ �����̸� �Ȱ��� ���� �����ڸ� ȣ���Ѵ�.
    // ���� pc3 = pc2; �� �ߴٸ� �̴� ����� ���Կ������̴�.

    pc1.show_status();
    pc2.show_status();

    return 0;
}

// ����Ե� C++ compiler �� Default Copy Constructor ���� �����ϰ� �ִ�. 
// ���� �� �ڵ忡�� copy constructor �� ����� �����ص� ������ ��Ȯ�� ������ ����� ����Ѵ�.
*/
/* Default Copy Constructor's limitation */
/*
#include <iostream>
#include <string.h>

class Photon_Cannon{
    int hp, shield;
    int damage;
    int coord_x, coord_y;

    char *name;     // �̸� �߰�

    public:
     Photon_Cannon(int x, int y);
     Photon_Cannon(int x, int y, const char *cannon_name);
     ~Photon_Cannon();   

     void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char*cannon_name){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);      // name ���ڿ��� cannon_name ���ڿ��� ����
}
Photon_Cannon::~Photon_Cannon(){
    if(name)    delete[] name;
}
void Photon_Cannon::show_status(){
    std::cout << "*** Photon Cannon " << name << " ***" << std::endl;
    std::cout << "Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();

    return 0;
}
*/
// �� �ڵ带 �����غ��� ��Ÿ�� ������ �߻��Ѵ�.
// �� �׷���? Default copy constructor �� ������ ���� ���ǵǾ��� ���̴�.
/*
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    name = pc.name;
}
*/
// hp, shield,... �׸��� name ���� ��� ���� ���� ������ �ȴ�.
// name �� ���ٸ�, �� �� ���� �����Ͱ� ���� ���� �����ٴ� ���� ���� �ּҰ��� ����Ų�ٴ� ���̵ȴ�.
// ��, �츮�� pc1 �� name �� �������� �Ҵ�޾Ƽ� ����Ű�� �ִ� �޸𸮸� 
// pc2 �� name �� ���� ����Ű�� �Ǵ� ���̴�.

// ���� �� ���¿����� �� ������ ����.

// ������ main() �Լ��� ����Ǳ� ������ �����Ǿ��� ��ü���� �ı��Ǹ鼭 
// destructor �� ȣ���� �� ������ �߻��Ѵ�.

// ���� pc1 �� ���� �ı��Ǿ��ٰ� �غ���
// �Ҹ��ڴ� pc1 �� ������ ��� �ı� �԰� ���ÿ� �ּҿ� �Ҵ��� �޸𸮱��� delete �ϰ� �ȴ�.
// ������ pc2 �� name �� ������ �޸��� �ּҸ� ����Ű�� �ִ�.

// ���� pc2 �� destructor �� ȣ��Ǹ� name �� NULL �� �ƴϹǷ� delete[] name; �� ����Ǵµ�
// �̹� ������ �޸𸮿� �����ؼ� �ٽ� �����Ϸ��� �߱� ������ ��Ÿ�� ������ �߻��� ���̴�.

// �ذ���
#include <iostream>
#include <string.h>

class Photon_Cannon{
    int hp, shield;
    int damage;
    int coord_x, coord_y;

    char *name;     // �̸� �߰�

    public:
     Photon_Cannon(int x, int y);
     Photon_Cannon(int x, int y, const char *cannon_name);
     Photon_Cannon(const Photon_Cannon &pc);
     ~Photon_Cannon();   

     void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char*cannon_name){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);      
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc){
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
    // name = pc.name ó�� ������ �ٷ� �����ϴ� ��������(shallow copy)�� �ƴ϶�
    // �޸𸮸� ���� �Ҵ��ؼ� ������ �����ϴ� ���� ����(deep copy)�� �̿��Ѵ�.
    // ���� ��ü pc1 �� ����� copy constructor �� �̿��Ͽ� ��ü pc2 �� �����ߴٸ�,
    // pc1.name �� pc2.name �� ���� �ٸ� �ּҰ��� ����Ų��.
}

Photon_Cannon::~Photon_Cannon(){
    if(name)    delete[] name;
}
void Photon_Cannon::show_status(){
    std::cout << "*** Photon Cannon " << name << " ***" << std::endl;
    std::cout << "Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();

    return 0;
}